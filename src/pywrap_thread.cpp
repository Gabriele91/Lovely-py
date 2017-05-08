//Lovely
#include <lovely.hpp>
//no lua thread
#define LOVE_THREAD_LUATHREAD_H
#define LOVE_THREAD_CHANNEL_H
// Love header
#include <common/config.h>
#include <modules/thread/threads.h>
#include <modules/thread/sdl/Thread.h>
#include <modules/thread/sdl/threads.h>
// Love implementation
#include <modules/thread/threads.cpp>
#include <modules/thread/sdl/Thread.cpp>
#include <modules/thread/sdl/threads.cpp>