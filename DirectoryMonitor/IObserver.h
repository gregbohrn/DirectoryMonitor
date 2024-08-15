#ifndef IOBSERVER_H
#define IOBSERVER_H

// System Includes
#include <string>

// Namespaces
using namespace std;


// //////////////////////////////////////////////////////////////
// Class Definition
// //////////////////////////////////////////////////////////////
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void OnFileAdded(const string& filename) = 0;
    virtual void OnFileRemoved(const string& filename) = 0;
};
typedef IObserver* IObserverPtr;

#endif // IOBSERVER_H