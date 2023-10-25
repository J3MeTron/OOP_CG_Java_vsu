#include <QtTest>

// add necessary includes here

class TriangleTests : public QObject
{
    Q_OBJECT

public:
    TriangleTests();
    ~TriangleTests();

private slots:
    void test_case1();

};

TriangleTests::TriangleTests()
{

}

TriangleTests::~TriangleTests()
{

}

void TriangleTests::test_case1()
{

}

QTEST_APPLESS_MAIN(TriangleTests)

#include "tst_triangletests.moc"
