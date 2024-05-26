#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MaxElement = 1000;

void GetInput(int& count, float intervals[], float fi[], double& sum_fi)
{
    sum_fi = 0;
    float max_num = fi[0];
    do
    {
        printf("How many element do you have? \"less than %d\"\n", MaxElement);
        cin >> count;
    } while (count > MaxElement);

    for (int i = 1; i <= count; i++)
    {
        cout << "\nInterval[" << i << "]" << " from what? ";
        cin >> intervals[i];
        cout << "Enter It's frequancy. ";
        cin >> fi[i];
        cout << endl;
        sum_fi += fi[i];
        if (fi[i] > max_num)
            max_num = fi[i];
    }
}

void CalculateMidPoints(int count, float intervals[], float fi[], double sum_fi, double& sum_xifi, double& sum_xi2fi)
{
    double l = 0, cf = 0;
    for (int i = 1; i <= count; i++)
    {
        if (i < count)
            l = intervals[i + 1] - intervals[i];
        else
            l = intervals[i] - intervals[i - 1];

        double xi = intervals[i] + l / 2;
        double xifi = fi[i] * xi;
        double xi2fi = fi[i] * pow(xi, 2);
        sum_xifi += xifi;
        sum_xi2fi += xi2fi;
        cf += fi[i];

        cout << setw(9) << "Mid point [" << i << "] = " << setw(9) << xi << "|";
        cout << setw(9) << "Xifi [" << i << "] = " << setw(9) << xifi << "|";
        cout << setw(9) << "Xi2fi [" << i << "] = " << setw(9) << xi2fi << "|";
        cout << setw(9) << "Cf [" << i << "] = " << setw(9) << cf << endl;
    }

    cout << "------------------------------\n";
    cout << "Sum of fi = " << sum_fi << endl;
    cout << "Sum of xifi = " << sum_xifi << endl;
    cout << "Sum of xi2fi = " << sum_xi2fi << endl;
}

void CalculateStatistics(double sum_fi, double sum_xifi, double sum_xi2fi)
{
    double mean = sum_xifi / sum_fi;
    double variance = (1 / sum_fi) * (sum_xi2fi - (sum_fi * pow(mean, 2)));

    cout << "Mean = " << mean << endl;
    cout << "Variance = " << variance << endl;
}

void CalculateNull()
{
    /*float calc_division = () / ();
    float mode = max_num + calc_division * l;*/
}

void ResetScreen()
{
    system("cls");
}

void StartProgram()
{
    float intervals[MaxElement], fi[MaxElement];
    double sum_fi = 0, sum_xifi = 0, sum_xi2fi = 0;
    int count = 0;
    char AnyQuestions = 'Y';

    do
    {
        ResetScreen();
        GetInput(count, intervals, fi, sum_fi);
        cout << "------------------------------\n";

        CalculateMidPoints(count, intervals, fi, sum_fi, sum_xifi, sum_xi2fi);
        cout << "------------------------------\n";

        CalculateStatistics(sum_fi, sum_xifi, sum_xi2fi);
        cout << "------------------------------\n";

        cout << "\nDo you have any questions? Y/N\n";
        cin >> AnyQuestions;

        if (AnyQuestions != 'Y' && AnyQuestions != 'y')
            cout << "\n*__________________All Rights Reversed To: Abdalrahman Saed \"2024\"___________________*\n";

    } while (AnyQuestions == 'Y' || AnyQuestions == 'y');

}

int main()
{
    StartProgram();

    return 0;
}
