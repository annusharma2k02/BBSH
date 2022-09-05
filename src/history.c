#include "libraries.h"

static hist localHist;

void setupHist()
{
    localHist.no_entries = 0;
    localHist.entries = calloc(MAX_HIST_SIZE, sizeof(str));
    localHist.last_added = -1;

    FILE *fp = fopen(HIST_PATH, "r");
    if (!fp)
        return;

    char line[INPUTLENGTH_MAX];

    while (fgets(line, sizeof(line), fp))
    {
        localHist.entries[localHist.no_entries] = strdup(line);
        localHist.entries[localHist.no_entries][strlen(line) - 1] = '\n';
        localHist.entries[localHist.no_entries][strlen(line)] = '\0';
        localHist.no_entries++;
        localHist.last_added++;
    }

    fclose(fp);
}

void addHist(str command)
{
    for (int i = 0; i < localHist.no_entries; ++i)
    {
        if (strlen(command) != strlen(localHist.entries[i]) - 1)
            continue;
        if (!strncasecmp(localHist.entries[i], command, strlen(command)))
            return;
    }
    localHist.last_added = (localHist.last_added + 1) % MAX_HIST_SIZE;
    localHist.entries[localHist.last_added] = strdup(command);
    localHist.entries[localHist.last_added][strlen(command)] = '\n';
    localHist.entries[localHist.last_added][strlen(command) + 1] = '\0';
    localHist.no_entries = (localHist.no_entries < MAX_HIST_SIZE) ? localHist.no_entries + 1 : localHist.no_entries;
}

void writeHist()
{
    FILE *fp = fopen(HIST_PATH, "w");
    if (!fp)
        exit(1);

    int i = (localHist.no_entries < MAX_HIST_SIZE) ? 0 : localHist.last_added + 1;

    for (int j = 0; j < localHist.no_entries; ++j)
    {
        fputs(localHist.entries[i % MAX_HIST_SIZE], fp);
        i++;
    }
    // fputs(localHist.entries[(i + localHist.last_added) % MAX_HIST_SIZE], fp);

    fclose(fp);
}

void history()
{
    writeHist();
    setupHist();
    int i = (localHist.no_entries < MAX_HIST_SIZE) ? 0 : localHist.last_added + 1;
    int j = (localHist.no_entries < HIST_DISPLAY) ? 0 : localHist.last_added - 9;

    for (; j < localHist.no_entries; ++j)
    {
        printf("%s", localHist.entries[j]);
        i++;
    }
}