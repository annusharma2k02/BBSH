// System Libraries 

#include <assert.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <math.h>
#include <pwd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// Programmer Defined Libraries

#include "print.h"
#include "path.h"
#include "helpers.h"
#include "input.h"
#include "commands.h"
#include "history.h"
#include "signals.h"
#include "jobpool.h"

#ifndef _LIBRARIES_H_
#define _LIBRARIES_H_

// Custom Headers

#define TRUE 1
#define true 1
#define FALSE 0
#define false 0

#define bool short int

#define str char*
#define str_array char**

#endif