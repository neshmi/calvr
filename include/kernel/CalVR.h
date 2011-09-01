/**
 * @file CalVR.h
 */

#ifndef CALVR_MAIN_H
#define CALVR_MAIN_H

#include <osg/ArgumentParser>

#include <string>

namespace cvr
{

class ConfigManager;
class ComController;
class TrackingManager;
class InteractionManager;
class Navigation;
class CVRViewer;
class ScreenConfig;
class SceneManager;
class CollaborativeManager;
class MenuManager;
class FileHandler;
class PluginManager;
class ThreadedLoader;

/**
 * @brief Main class for the CalVR framework.  Sets up all other core classes 
 * and contains the main run loop.
 */
class CalVR
{
    public:
        CalVR();
        virtual ~CalVR();

        /**
         * @brief get static self pointer
         */
        static CalVR * instance();

        /**
         * @brief does main framework init
         */
        bool init(osg::ArgumentParser & args, std::string home);

        /**
         * @brief main run loop, does not return util quit is signaled
         */
        void run();

        /**
         * @brief returns the set home directory for the CalVR install
         */
        std::string & getHomeDir() { return _home; }

        std::string & getHostName() { return _hostName; }

    protected:
        static CalVR * _myPtr; ///< static self pointer

        std::string _home; ///< CalVR home directory
        std::string _hostName;

        ConfigManager * _config;
        ComController * _communication;
        TrackingManager * _tracking;
        InteractionManager * _interaction;
        Navigation * _navigation;
        CVRViewer * _viewer;
        ScreenConfig * _screens;
        SceneManager * _scene;
        CollaborativeManager * _collaborative;
        MenuManager * _menu;
        FileHandler * _file;
        PluginManager * _plugins;
        ThreadedLoader * _threadedLoader;
};

}

#endif
