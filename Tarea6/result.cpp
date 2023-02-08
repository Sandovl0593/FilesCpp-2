#include <string>
#include <iostream>
#include "P6.h"
using namespace std;

namespace test {
    class student_t {
        string name;
        string surname;
        double grade{};
    public:
        student_t() = default;
        student_t(string name, string surname, double  grade):
                name(std::move(name)), surname(surname), grade(grade) {}
        [[nodiscard]] string get_name() const { return name; }
        [[nodiscard]] string get_surname() const { return surname; }
        [[nodiscard]] double get_grade() const { return grade; }
    };
}
int main() {
    stack<test::student_t> s1;
    int n{};
    cin >> n;
    string nombre, apellido;
    double nota;
    while (n-- > 0) {
        cin >> nombre >> apellido >> nota;
        s1.push(test::student_t{nombre, apellido, nota});
    }
    string name_tobe_found;

    // getline(cin, name_tobe_found);
    // auto a1 = find_in_stack(s1, [=](auto a) { return a.get_nombre() == name_tobe_found; });
    // cout << a1.get_nombre() << " " << a1.get_apellido() << " " << a1.get_nota() << endl;

    cin >> name_tobe_found;
    auto comp = [=](test::student_t a) -> bool {
        return a.get_name() == name_tobe_found;
    };
    auto a1 = find_in_stack<test::student_t> (s1, comp);
    cout  << a1.get_name() << " " << a1.get_surname() << " "
          << a1.get_grade() << endl;
}