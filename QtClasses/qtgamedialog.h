#ifndef QTGAMEDIALOG_H
#define QTGAMEDIALOG_H

#include <QDialog>
#include "observer.h"
#include "option.h"
#include "character.h"

namespace Ui { class QtGameDialog; }

class QtGameDialog : public QDialog, public Observer
{
  Q_OBJECT

public:
  explicit QtGameDialog(QWidget *parent = 0);
  ~QtGameDialog();


protected:
  void keyPressEvent(QKeyEvent *);

private slots:
  void Start();

private:
  Ui::QtGameDialog *ui;

  int m_key_pressed;

  std::vector<Option> m_options;

  void DoChapter();

  void CharacterChanged(const Character& character) override;
  int GetNumberOfCharsPerLine() const noexcept override { return 2000000000; }

  void Wait() override;

  void ShowText(const std::string& text) override;
  Option RequestOption(const std::vector<Option>& options) override;

  void UpdateStats();
};

#endif // QTGAMEDIALOG_H
