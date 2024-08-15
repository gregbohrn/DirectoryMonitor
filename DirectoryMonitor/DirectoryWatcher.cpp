// System Includes
#include <filesystem>
#include <thread>
#include <chrono>

// Project Includes
#include "DirectoryWatcher.h"

// Namespaces
namespace fs = std::filesystem;



// //////////////////////////////////////////////////////////////
// CTOR
// //////////////////////////////////////////////////////////////
DirectoryWatcher::DirectoryWatcher(const string& directoryPath) : _directoryPath(directoryPath) {}


// //////////////////////////////////////////////////////////////
// Public Methods
// //////////////////////////////////////////////////////////////
void DirectoryWatcher::Subscribe(IObserver* observer)
{
    _observers.push_back(observer);
}

void DirectoryWatcher::Unsubscribe(IObserver* observer)
{
    _observers.erase(remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

void DirectoryWatcher::StartMonitoring(int pollIntervalMs/* = 1000*/)
{
    set<string> previousFiles = DirectoryFileList();

    while (_isMonitoring)
    {
        // Wait so we do not thrash
        this_thread::sleep_for(chrono::milliseconds(pollIntervalMs));

        // Get the list that is in the directory at this time (to comare to previous)
        set<string> currentFiles = DirectoryFileList();

        // Detect added files
        for (const auto& file : currentFiles)
        {
            if (previousFiles.find(file) == previousFiles.end())
            {
                NotifyFileAdded(file);
            }
        }

        // Detect removed files
        for (const auto& file : previousFiles)
        {
            if (currentFiles.find(file) == currentFiles.end())
            {
                NotifyFileRemoved(file);
            }
        }

        // Update previous list and start again
        previousFiles = currentFiles;
    }
}

void DirectoryWatcher::StopMonitoring()
{
    _isMonitoring = false;
}


// //////////////////////////////////////////////////////////////
// Private Methods
// //////////////////////////////////////////////////////////////
set<string> DirectoryWatcher::DirectoryFileList()
{
    set<string> files;
    for (const auto& entry : fs::directory_iterator(_directoryPath))
    {
        files.insert(entry.path().filename().string());
    }
    return files;
}

void DirectoryWatcher::NotifyFileAdded(const string& filename)
{
    for (auto observer : _observers)
    {
        observer->OnFileAdded(filename);
    }
}

void DirectoryWatcher::NotifyFileRemoved(const string& filename)
{
    for (auto observer : _observers)
    {
        observer->OnFileRemoved(filename);
    }
}
