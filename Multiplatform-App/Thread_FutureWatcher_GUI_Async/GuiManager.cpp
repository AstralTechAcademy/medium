#include "GuiManager.h"

void GuiManager::createWatcher(QString id, QFuture<void>& future)
{
    watchers_.insert(id, std::make_shared<QFutureWatcher<void>>(new QFutureWatcher<void>()));
    connect(watchers_[id].get(), &QFutureWatcher<void>::finished, this, [] {emit GuiManager::getInstance()->incremented();});
    watchers_[id]->setFuture(future);
}