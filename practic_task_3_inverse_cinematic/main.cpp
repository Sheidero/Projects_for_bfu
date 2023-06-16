#include <iostream>
#include <cmath>
#include <vector>

class ReverseCinematica{
private:
    std::vector<double> m_links;
public:
    void SetLinks(std::vector<double> links){
        m_links = links;
    }
    std::vector<double> Solve(double x, double y){
        std::vector<double> angles;
        double a = sqrt(pow(x, 2) + pow(y, 2));
        double ug1 = std::acos(x / a);
        double ug2 = std::acos((pow(m_links[0], 2) - pow(m_links[1], 2) + pow(a, 2)) / (2 * a * m_links[0]));
        angles.push_back(ug1 - ug2);
        angles.push_back(M_PI - std::acos((pow(m_links[0], 2) + pow(m_links[1], 2) - pow(a, 2)) / (2 * m_links[0] * m_links[1])));
        return angles;
    }
};
int main() {
    ReverseCinematica cinematica;
    cinematica.SetLinks({10, 10});
    std::vector<double> angles = cinematica.Solve(7, 7);
    std::cout << "alpha = " << angles[0] << " ; beta = " << angles[1] << std::endl;
    return 0;
}