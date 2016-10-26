#include "historymanager.hpp"

HistoryManager::HistoryManager(QObject *parent) : QObject(parent) {}

HistoryManager::HistoryManager(const QString &file, QObject *parent) {}

void HistoryManager::load(const QString &file) {}

void HistoryManager::save(const QString &file) {}
