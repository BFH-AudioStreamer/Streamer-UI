#ifndef IBACKENDCONNECTOR_H
#define IBACKENDCONNECTOR_H

class IBackendConnector
{
public:
    IBackendConnector();
    virtual ~IBackendConnector();

    virtual void song_title() = 0;
    virtual void artist() = 0;
    virtual void album() = 0;
    virtual void play_next() = 0;
    virtual void play_previous() = 0;
    virtual void play_stop() = 0;
    virtual void play_toggle_pause() = 0;
    virtual void bit_rate() = 0;
    virtual void track_total_time() = 0;
    virtual void track_elapsed_time() = 0;
    virtual void album_art_uri() = 0;
    virtual void set_search() = 0;
    virtual void control_capabilities() = 0;

};

#endif // IBACKENDCONNECTOR_H
