#include <iostream>
#include <string>
#include <vector>

/**
 * @brief принимает сторку input и возврошает принятую страку, в которой всё элементы "." заменены на "[.]"
 * 
 * @param input строка 
 */  
std::string fun1(std::string input){
    for(int index = input.find("."); index != -1; index = input.find(".")){
        input.replace(index, 1, "[!]");
    }
    for(int index = input.find("!"); index != -1; index = input.find("!")){
        input.replace(index, 1, ".");
    }
    return input;
}

/**
 * @brief принимает вектор строк и вектор чисел, возвращает некое число, полученное в результате анализа двух вектор
 * 
 * @param orders вектор строк
 * @param time вектор чисел
 */  
int fun2(std::vector<std::string> orders, std::vector<int> time){
    int delivery_time = 0;
    for(int i = 0; i < orders.size(); i++){
        delivery_time += orders[i].size();
    }
    for(int i = orders.size() - 1; i >= 0; i--){
        if(orders[i].find("F") != std::string::npos){
            for(int ii = 0; ii < i; ii++){
                delivery_time += time[ii];
            }
            break;
        }
    }
    for(int i = orders.size() - 1; i >= 0; i--){
        if(orders[i].find("E") != std::string::npos){
            for(int ii = 0; ii < i; ii++){
                delivery_time += time[ii];
            }
            break;
        }
    }
    for(int i = orders.size() - 1; i >= 0; i--){
        if(orders[i].find("B") != std::string::npos){
            for(int ii = 0; ii < i; ii++){
                delivery_time += time[ii];
            }
            break;
        }
    }
    return delivery_time;
}

/**
 * @brief принимает вектор строк, вектор символов вектор чисел, возвращает некое число, полученное в результате анализа трёх вектор
 * 
 * @param words вектор строк
 * @param letters вектор символов
 * @param score вектор чисел
 */ 
int fun3(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score){
    int price = 0, r = 0, t;
    for(int i = 0; i < words.size(); i++){
        std::vector<char> l = letters;
        t = 0;
        for(int ii = 0; ii < words[i].size(); ii++){
            for(int iii = 0; iii < l.size(); iii++){
                if(words[i][ii] == l[iii]){
                    r += int(words[i][ii]) - 97;
                    l[iii] = char(" ");
                    t++;
                }
            }
        }
        if(t < words[i].size()){
            r = 0;
        }
        std::cout << words[i] << " " << r << std::endl;
        if(r > price){
            price = r;
        }
        r = 0;
    }
    return price;
}

int main(int, char**){
    std::setlocale(LC_ALL, "Russian");
    /*/
    std::string input;
    std::cin >> input;
    input = fun1(input);
    std::cout << input  << std::endl;
    //*/
    /*/
    std::vector<std::string> orders =  {"F", "E", "FE", "FF"};
    std::vector<int> time = {2, 3, 4};
    int delivery_time = fun2(orders, time);
    std::cout << delivery_time << std::endl;
    //*/
    //*/
    std::vector<std::string> words = {"go", "find", "fii", "by", "pneumonoultramicroscopicsilicovolcanoconiosis", "step"};
    std::vector<char> letters = {'q', 'f', 'i', 'n', 'd'};
    std::vector<int> score = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    int price = fun3(words, letters, score);
    std::cout << price << std::endl;
    //*/
    return 0;
}
