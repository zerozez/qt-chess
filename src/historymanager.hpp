#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP

#include <QObject>

/**
 * @brief The HistoryManager class.
 *
 *      Allow to load and save history out of file
 */
class QFile;
class HistoryManager : public QObject {
  Q_OBJECT
 public:
  explicit HistoryManager(QObject *parent = 0);
  HistoryManager(const QString &file, QObject *parent = 0);

  /**
   * @brief Load game history
   * @param file Load from \a file. If input is empty
   *      trying to load from \a default place
   */
  void load(const QString &file = "");

  /**
   * @brief Save game history
   * @param file Save in to \a file. If input is empty
   *      trying to save in \a default place
   */
  void save(const QString &file = "");

 private:
  QFile *m_file; /**< Working file*/

 private:
  QString const s_default = "game.sav";
};

#endif  // HISTORYMANAGER_HPP
