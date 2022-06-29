
#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H
#include <QObject>
#include <QFutureWatcher>
#include <QMap>
#include <memory>

class GuiManager : public QObject
{

    Q_OBJECT
public:
    //Singleton class
    static std::shared_ptr<GuiManager> getInstance(void)
    {
        if (!instance_)
            instance_ = std::shared_ptr<GuiManager>(new GuiManager);
        return instance_;
    }
    
signals:
    void incremented (void);
    void updatedNumberThreads (const QString& id);

public:
    void createWatcher(QString id, QFuture<void>& future);

private:
    inline static std::shared_ptr<GuiManager> instance_ = nullptr;
    QMap<QString, std::shared_ptr<QFutureWatcher<void>>> watchers_;

};

#endif