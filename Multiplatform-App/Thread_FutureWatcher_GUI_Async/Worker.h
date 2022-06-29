
#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <memory>

class Worker
{

public:
    void bigTask  (int idx);

};

#endif