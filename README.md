[![Build Status](https://travis-ci.com/skyejonke/yapp.svg?branch=master)](https://travis-ci.com/skyejonke/yapp)
# Yet Another Podcast Player

Finally, a podcast player that just works.

Made for the 2019 Technica Hackathon


## Todo

- Object Persistence

- Return to last spot in mp3

- GUI

## Building

You ***must*** be on linux for this application to work. You also need the following dependences:

- mpv
- git
- libmpv
- pugixml
- libopencv
- skyelib

pugixml, libmpv, and skyelib are provided as git submodules

From there just run

```bash
cmake .
make
./yapp
```
