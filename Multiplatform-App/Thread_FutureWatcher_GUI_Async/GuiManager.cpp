#include "GuiManager.h"

void GuiManager::createWatcher(QString id, QFuture<void>& future)
{
    watchers.insert(id, std::make_shared<QFutureWatcher<void>>(new QFutureWatcher<void>()));
    connect(watchers[id].get(), &QFutureWatcher<void>::finished, this, [] {emit GuiManager::getInstance()->incremented();});
    watchers[id]->setFuture(future);
}