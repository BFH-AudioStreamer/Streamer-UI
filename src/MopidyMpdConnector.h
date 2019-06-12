#ifndef MOPIDYMPDCONNECTOR_H
#define MOPIDYMPDCONNECTOR_H

#include <string>
#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include <mpd/message.h>

#include "MpdConnector.h"
#include "MopidyConnector.h"
#include "IBackendConnector.h"

using namespace std;

class MopidyMpdConnector : IBackendConnector
{
private:
    string hostname;
    int port;
    MpdConnector mpdConnenctor;
    MopidyConnector mopidyConnector;

public:
    MopidyMpdConnector();
};

#endif // MOPIDYMPDCONNECTOR_H
