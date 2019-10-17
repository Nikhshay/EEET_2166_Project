/*
 * TL_I1.h
 *
 *  Created on: 29Sep.,2019
 *      Author: LukeT
 */

#ifndef TL_I1_H_
#define TL_I1_H_

//string defines for input switch statement
#define B                   66
#define Q                   81
#define D                   68
#define N                   78
#define O                   79
#define A                   65
#define T                   84
#define F                   70
#define S                   83
#define E                   69
#define W                   87
#define R                   82
#define Y                   89
#define G                   71
#define L                   76
#define P                   80


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Used for sleep()
#include <pthread.h>
#include <time.h>
#include <sys/netmgr.h>
#include <stdbool.h>
#include <string.h>
// Includes for hardware "gpioController()"
#include <hw/inout.h>      // for in32() and out32();
#include <sys/mman.h>      // for mmap_device_io();
#include <sys/neutrino.h>  // for ThreadCtl( _NTO_TCTL_IO_PRIV , NULL);
#include <stdint.h>        // for unit32 types
#include <sys/procmgr.h>

enum lightState     {red, yellow, green, off, flashing};
enum mode     {automatic, manual};
enum sequenceState  {initial, day1, day2, day3, day4,   day5,   day6, day7, day8, day9, day10,   day11,   day12,
                                                night4, night5, night6,                 night10, night11, night12};
                          // Night sequences 4,5,6 and 10,11,12 are equal with the same day sequences numbers
struct light
{
    enum lightState pedestrian1;
    enum lightState left;
    enum lightState straight;
    enum lightState right;
    enum lightState pedestrian2;
};

struct intersection
{
    struct light north;
    struct light south;
    struct light east;
    struct light west;
    enum sequenceState seqState;
}intersection;


struct lightMode
{
    enum mode pedestrian1;
    enum mode left;
    enum mode straight;
    enum mode right;
    enum mode pedestrian2;
};

struct intersectionMode
{
    struct lightMode north;
    struct lightMode south;
    struct lightMode east;
    struct lightMode west;
}intersectionMode;

typedef union
{
	struct _pulse   pulse;
} timer;



#endif /* TL_I1_H_ */
