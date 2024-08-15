#ifndef DIRECTORY_WATCHER_H
#define DIRECTORY_WATCHER_H

// System Includes
#include <string>
#include <vector>
#include <set>

// Project Includes
#include "IObserver.h"


// //////////////////////////////////////////////////////////////
// Class Definition
// //////////////////////////////////////////////////////////////
class DirectoryWatcher
{
public:
    // CTOR / DTOR
    DirectoryWatcher(const std::string& directoryPath);
    virtual ~DirectoryWatcher() {}

    // Public Methods
    void Subscribe(IObserver* observer);
    void Unsubscribe(IObserver* observer);
    void StartMonitoring(int pollIntervalMs = 1000);
    void StopMonitoring();

private:
    // Private Methods
    set<string> DirectoryFileList();
    void NotifyFileAdded(const std::string& filename);
    void NotifyFileRemoved(const std::string& filename);

    // Attributes
    string _directoryPath;
    vector<IObserverPtr> _observers;
    bool _isMonitoring = true;
};

#endif // DIRECTORY_WATCHER_H