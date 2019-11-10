#include "player.hpp"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
#include "skyelib.hpp"

std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}
static inline void check_error(int status)
{
    if (status < 0) {
        printf("mpv API error: %s\n", mpv_error_string(status));
        exit(1);
    }
}

player::player(episode* ep){
    mpv_handle *ctx = mpv_create();
  if (!ctx) {
        printf("failed creating context\n");
    }
        // Enable default key bindings, so the user can actually interact with
    // the player (and e.g. close the window).
    check_error(mpv_set_option_string(ctx, "input-default-bindings", "yes"));
    mpv_set_option_string(ctx, "input-vo-keyboard", "yes");
    int val = 1;
    int nval = 0;
    int64_t* spot = ep->getSpot();
    check_error(mpv_set_option(ctx, "osc", MPV_FORMAT_FLAG, &val));
    //check_error(mpv_set_option(ctx, "vid", MPV_FORMAT_FLAG, &nval));

    // Done setting up options.
    check_error(mpv_initialize(ctx));

    // Play this file.
   // std::cout << ep->getPath().c_str() << std::endl;
    std::string dir = "<pwd>/<path>";
    skyelib::replace(dir,"<pwd>",GetCurrentWorkingDir());
    skyelib::replace(dir,"<path>",ep->getPath());
    //std::string spt = "seek " + std::to_string(spot) + " absolute";
    const char *cmd[] = {"loadfile", dir.c_str() , NULL};
3
    check_error(mpv_command(ctx, cmd));
//    check_error(mpv_command(ctx, cma));


    // Let it play, and wait until the user quits.
    while (1) {
        mpv_event *event = mpv_wait_event(ctx, 10000);
        printf("event: %s\n", mpv_event_name(event->event_id));
	//result = mpv_get_property_string(ctx, "time-pos");
	int64_t *result;
          mpv_get_property(ctx, "time-pos", MPV_FORMAT_INT64, &result);
	 ep->setSpot(result);
          //mpv_free(result);
        if (event->event_id == MPV_EVENT_SHUTDOWN){
		//ep->setSpot(mpv_get_time_pos(mpv_handle *ctx));
            break;
	    }
	mpv_terminate_destroy(ctx);
}
}

