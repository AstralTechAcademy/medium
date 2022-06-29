#include "Worker.h"
#include "GuiManager.h"


void Worker::bigTask (int idx)
{
    QString id = QString::number(idx);
    QFuture<void> future = QtConcurrent::run([&] {
        QThread::currentThread()->thread()->msleep(1000 + (rand() % 1000));
    });
    GuiManager::getInstance()->updatedNumberThreads(id);
    GuiManager::getInstance()->createWatcher(id, future);

}