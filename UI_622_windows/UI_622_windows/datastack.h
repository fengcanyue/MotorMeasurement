#ifndef DATASTACK_H
#define DATASTACK_H
#include <QStack>
#include <QObject>
#include <QDateTime>
typedef struct{
   double torsion_value;
   double torsion_max;
   double speed_value;
   double speed_max;
   double power_value;
   QDateTime time;
}ItemType;
class DataStack
{
public:
    DataStack();
    QStack<ItemType> stack;
public slots:
};

#endif // DATASTACK_H
