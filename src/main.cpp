#include "funcs.cpp"

using namespace std;

int main() {

    classData test;
    cout << "Average: " << getAvg(test) << endl;

    cout << "best Topic: " << bestTopic(test) << endl;
    cout << "worst Topic: " << worstTopic(test) << endl;

    cout << "best Assessment Type: " << bestAssessmentType(test) << endl;
    cout << "worst Assessment Type: " << worstAssessmentType(test) << endl;

    return 0;
}
