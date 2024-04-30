class Tables : public Section {
public:
    HANDLE hConsole;
    std::vector<std::vector<Input>> myResult;
    Json m_json;
    Language language;
    int mySpace = 0;
    int my_lable_space = 0;
    bool m_star = true;
    Tables();
    void tableResult77(std::vector<Input> vec, std::string id, std::string label);
    void show_result_with_operator(std::vector<Input>* vec, std::string table_jop, std::string label);
    void display_table_menu(std::vector<std::vector<std::string>> vec, std::string word, std::string label, MenuEdit section);
   
    int get_lable_space(std::string label, std::string my_line, int title);
    bool get_star(std::string label, std::string my_line, int title);
    void setup_language();

    void get_culc_Result();
    int get_color_by_name(std::string color_name);
private:
    std::string get_text_search(std::vector <Input> vec);
};

Tables::Tables(){
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setup_language();
}

std::string Tables::get_text_search(std::vector <Input> vec) {
    std::string var;
    for (int i = 0; i < vec.size(); i++)
        var += vec[i].m_var1 + vec[i].m_operator;
    return var;
}

void Tables::get_culc_Result() {
    for (int i = 0; i < this->myResult.size(); i++) {
        std::vector<Input>m_vec = this->myResult.at(i);
        std::string value = m_vec[0].m_var1;
        for (int ii = 0; ii < this->myResult.at(i).size(); ii++)
            if (m_vec.at(ii).m_operator == "+")
                value = std::to_string(stof(value) + stof(m_vec.at(ii + 1).m_var1));
            else if (m_vec.at(ii).m_operator == "-")
                value = std::to_string(stof(value) - stof(m_vec.at(ii + 1).m_var1));
            else if (m_vec.at(ii).m_operator == "*")
                value = std::to_string(stof(value) * stof(m_vec.at(ii + 1).m_var1));
            else if (m_vec.at(ii).m_operator == "/")
                value = std::to_string(stof(value) / stof(m_vec.at(ii + 1).m_var1));
        this->myResult[i][0].m_result = value;
    }
}

int Tables::get_color_by_name(std::string color_name) {
    if (color_name == "blue")
        return 1;
    else if (color_name == "green")
        return 2;
    else if (color_name == "cyan")
        return 3;
    else if (color_name == "red")
        return 4;
    else if (color_name == "purple")
        return 5;
    else if (color_name == "yellow_dark")
        return 6;
    else if (color_name == "yellow_dark")
        return 7;
    else if (color_name == "default_white")
        return 8;
    else if (color_name == "gray_grey")
        return 9;
    else if (color_name == "bright_blue")
        return 10;
    else if (color_name == "bright_green")
        return 11;
    else if (color_name == "bright_cyan")
        return 12;
    else if (color_name == "pink_magenta")
        return 13;
    else if (color_name == "yellow")
        return 14;
    else if (color_name == "bright_white")
        return 15;
    else
        return 7;
}

void Tables::setup_language() {
    std::vector<std::string> names = { "addition", "search", "edit" };
    App app;
    m_json = app.read_setting();
    const int size = 3;
    AddSearchEdit add_search_edit[size];
    for(int i = 0; i < names.size(); i++)
        add_search_edit[i] = app.read_add_search_edit(names[i], m_json);
    this->myResult = app.read_result(m_json);
    Table m_table = app.read_table(m_json);
    Colors m_colors = app.read_colors(m_json);
    Main m_main = app.read_main(m_json);
    Dialog m_dialog = app.read_dialog(m_json);
    Help m_help = app.read_Help(m_json);
    Confirm m_confirm = app.read_confirm(m_json);
    Delete m_delete = app.read_delete(m_json);
    this->language = Language(add_search_edit[0], m_main, m_table, m_colors, m_dialog, m_help, add_search_edit[1], add_search_edit[2], m_confirm, m_delete);
}

void Tables::tableResult77(std::vector<Input> vec, std::string id, std::string label) {

    std::vector<std::string> array1;
    int space = this->language.m_data_space;
    //string fill = this->language.m_data_fill;
    bool heddinIndex = this->language.m_heddin_data_address != "on" ? false : true;
    bool heddinResult = this->language.m_heddin_data_result != "on" ? false : true;
    vec[0].m_index = id;
    int sizeOfResult = 0, sizeOfIndex = 0;
    int temp_title_table;
    if (this->language.m_center_label)
        temp_title_table = this->language.m_data_title.length() < label.length() ? label.length() : this->language.m_data_title.length();
    else
        temp_title_table = this->language.m_data_title.length();

  
    if (this->language.m_type_table_operator == "on") {
        for (int i = 0; i < vec.size(); i++) {
            std::string var1 = this->language.m_value;
            std::string var2 = this->language.m_mark;
            for (int ii = 0; ii < space; ii++) {
                var1 = " " + var1 + " ";
                var2 = " " + var2 + " ";
            }
            if (vec.at(i).m_operator == "") {
                array1.push_back(var1);
            }
            else {
                array1.push_back(var1);
                array1.push_back(var2);
            }
            if (heddinResult && heddinIndex && i + 1 == vec.size()) {
                array1.push_back(this->language.m_total);
                array1.push_back(this->language.m_address);
                sizeOfResult = array1.size() - 2;
                sizeOfIndex = array1.size() - 1;
                for (int ii = 0; ii < space; ii++) {
                    array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                }
            }
            else if (heddinResult && i + 1 == vec.size()) {
                array1.push_back(this->language.m_total);
                sizeOfResult = array1.size() - 1;
                for (int ii = 0; ii < space; ii++)
                    array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
            }
            else if (heddinIndex && i + 1 == vec.size()) {
                array1.push_back(this->language.m_address);
                sizeOfIndex = array1.size() - 1;
                for (int ii = 0; ii < space; ii++)
                    array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
            }
        }





        for (int i = 0; i < vec.size(); i++) {
            for (int ii = 0; ii < space; ii++) {
                Input inp = vec.at(i);
                vec.at(i) = Input(" " + inp.m_var1 + " ",
                    " " + inp.m_operator + " ", " " + inp.m_result + " ", " " + inp.m_index + " ");
            }
        }


        if (heddinResult && heddinIndex) {
            int new_size = array1.size() - 2;
            for (int i = 0; i < new_size; i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                if (i == 0 && vec.at(0).m_var1.length() > array1[0].length()) {
                    std::string value = vec.at(i).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                //i+1
                else if (i % 2 == 0 && i > 1 && vec.at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                    std::string value = vec.at(index).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                else if (i > 0 && vec.at(index).m_operator.length() > array1[i].length()) {
                    std::string op = vec.at(index).m_operator;
                    int myLen = op.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";

                }
                if (array1[sizeOfResult].length() < vec.at(0).m_result.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfResult].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfResult] += " ";
                }
                if (array1[sizeOfIndex].length() < vec.at(0).m_index.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_index.length() - array1[sizeOfIndex].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfIndex] += " ";
                }
            }

        }
        else if (heddinResult || heddinIndex) {
            int new_size = array1.size() - 1;
            for (int i = 0; i < new_size; i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);

                if (i == 0 && vec.at(0).m_var1.length() > array1[0].length()) {
                    std::string value = vec.at(i).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                //i+1
                else if (i % 2 == 0 && i > 1 && vec.at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                    std::string value = vec.at(index).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                else if (i > 0 && vec.at(index).m_operator.length() > array1[i].length()) {
                    std::string op = vec.at(index).m_operator;
                    int myLen = op.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                if (heddinResult && array1[sizeOfResult].length() < vec.at(0).m_result.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfResult].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfResult] += " ";
                }
                else if (heddinIndex && array1[sizeOfIndex].length() < vec.at(0).m_index.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_index.length() - array1[sizeOfIndex].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfIndex] += " ";
                }
            }
        }
        else
            for (int i = 0; i < array1.size(); i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                if (i == 0 && vec.at(0).m_var1.length() > array1[0].length()) {
                    std::string value = vec.at(i).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                //i+1
                else if (i % 2 == 0 && i > 1 && vec.at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                    std::string value = vec.at(index).m_var1;
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                else if (i > 0 && vec.at(index).m_operator.length() > array1[i].length()) {
                    std::string op = vec.at(index).m_operator;
                    int myLen = op.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
            }



        std::string my_line = "";
        for (int i = 0; i < array1.size(); i++) {
            my_line += "+";
            for (int ii = 0; ii < array1[i].length(); ii++)
                my_line += "-";

            if (i + 1 == array1.size() && my_line.length() / 2 < temp_title_table) {
                int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                    ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                    temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
                for (int z = 0; z < size; z++) {
                    my_line += "-";
                    array1[array1.size() - 1] += " ";
                }
                my_line += "+\n";
            }
            else if (i + 1 == array1.size()) {
                int temp_size = my_line.size();
                my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
                array1[array1.size() - 1] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
            }
        }




        int size = (my_line.length() / 2) - (temp_title_table % 2 ? ((temp_title_table / 2) + 1) : temp_title_table / 2);
        mySpace = temp_title_table == (my_line.length() / 2) || temp_title_table < (my_line.length() / 2) ? size : my_line.length() / 4;









        bool star = temp_title_table > this->language.m_data_title.length() ?
            ((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) % 2 == 1 : true;
        int space_size = temp_title_table > this->language.m_data_title.length() ?
            ((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) % 2 == 0 ?
            (((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) / 2) + (mySpace - 1) :
            (((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) / 2) + mySpace : mySpace;
        int color_message = this->get_color_by_name(this->language.m_color_data_title);
        int color_table = this->get_color_by_name(this->language.m_color_data_table);
        SetConsoleTextAttribute(hConsole, color_message);
        std::string temp = "";
        for (int i = 0; i < space_size; i++)
            temp += " ";
        temp = star ? temp : temp + "*";
        std::cout << temp << this->language.m_data_title << std::endl;
        SetConsoleTextAttribute(hConsole, color_table);



       

        if (this->language.m_center_label) {
            this->my_lable_space = this->get_lable_space(label, my_line, this->language.m_data_title.length());
            this->m_star = this->get_star(label, my_line, this->language.m_data_title.length());
        }



        std::cout << my_line;
        for (int i = 0; i < array1.size(); i++) {
            std::cout << "|" << array1[i];
            if (i + 1 == array1.size())
                std::cout << "|" << std::endl;
        }
        std::cout << my_line << "|";
        if (heddinResult && heddinIndex) {
            int newSize = array1.size() - 2;
            for (int i = 0; i < newSize; i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                if (i == 0) {
                    Input inp = vec.at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i % 2 == 0 && i > 1) {
                    Input inp = vec.at(index);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i > 0) {
                    Input inp = vec.at(index);
                    if (inp.m_operator.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_operator.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_operator += " ";
                    }
                    std::cout << inp.m_operator << "|";
                }
                if (i + 1 == newSize) {
                    if (vec.at(0).m_result.length() < array1[sizeOfResult].length()) {
                        int mySize = array1[sizeOfResult].length() - vec.at(0).m_result.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_result += " ";
                    }
                    if (vec.at(0).m_index.length() < array1[sizeOfIndex].length()) {
                        int mySize = array1[sizeOfIndex].length() - vec.at(0).m_index.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_index += " ";
                    }
                    std::cout << vec.at(0).m_result << "|" << vec.at(0).m_index << "|";
                }
            }
        }
        else if (heddinResult || heddinIndex) {
            int newSize = array1.size() - 1;
            for (int i = 0; i < newSize; i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                if (i == 0) {
                    Input inp = vec.at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i % 2 == 0 && i > 1) {
                    Input inp = vec.at(index);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i > 0) {
                    Input inp = vec.at(index);
                    if (inp.m_operator.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_operator.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_operator += " ";
                    }
                    std::cout << inp.m_operator << "|";
                }
                if (heddinResult && i + 1 == newSize) {
                    if (vec.at(0).m_result.length() < array1[newSize].length()) {
                        int mySize = array1[newSize].length() - vec.at(0).m_result.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_result += " ";
                    }
                    std::cout << vec.at(0).m_result << "|";
                }
                else if (heddinIndex && i + 1 == newSize) {
                    if (vec.at(0).m_index.length() < array1[newSize].length()) {
                        int mySize = array1[newSize].length() - vec.at(0).m_index.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_index += " ";
                    }
                    std::cout << vec.at(0).m_index << "|";
                }
            }


        }
        else
            for (int i = 0; i < array1.size(); i++) {
                int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                if (i == 0) {
                    Input inp = vec.at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i % 2 == 0 && i > 1) {
                    Input inp = vec.at(index);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }
                else if (i > 0) {
                    Input inp = vec.at(index);
                    if (inp.m_operator.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_operator.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_operator += " ";
                    }
                    std::cout << inp.m_operator << "|";
                }

            }
            std::cout << std::endl << my_line;
    }
    else {
        for (int i = 0; i < vec.size(); i++) {
            std::string var1 = this->language.m_value;
            for (int ii = 0; ii < space; ii++)
                var1 = " " + var1 + " ";
            array1.push_back(var1);

            if (heddinResult && heddinIndex && i + 1 == vec.size()) {
                array1.push_back(this->language.m_total);
                array1.push_back(this->language.m_address);
                sizeOfResult = array1.size() - 2;
                sizeOfIndex = array1.size() - 1;
                for (int ii = 0; ii < space; ii++) {
                    array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                }
            }
            else if (heddinResult && i + 1 == vec.size()) {
                array1.push_back(this->language.m_total);
                sizeOfResult = array1.size() - 1;
                for (int ii = 0; ii < space; ii++) {
                    array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                }
            }
            else if (heddinIndex && i + 1 == vec.size()) {
                array1.push_back(this->language.m_address);
                sizeOfIndex = array1.size() - 1;
                for (int ii = 0; ii < space; ii++) {
                    array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                }
            }
        }



       




        if (heddinResult && heddinIndex) {
            int new_size = vec.size();
            for (int i = 0; i < new_size; i++) {
                vec.at(i).m_var1 = vec.at(i).m_var1 + " " + vec.at(i).m_operator;
                for (int ii = 0; ii < space; ii++) {
                    Input inp = vec.at(i);
                    vec.at(i) = Input(" " + inp.m_var1 + " ",
                        " " + inp.m_operator + " ", ii == 0 ? " = " + inp.m_result + " " : " " + inp.m_result + " ", " " + inp.m_index + " ");
                }
                std::string value = vec.at(i).m_var1;
                if (value.length() > array1[i].length()) {
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                if (array1[sizeOfResult].length() < vec.at(0).m_result.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfResult].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfResult] += " ";
                }
                if (array1[sizeOfIndex].length() < vec.at(0).m_index.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfIndex].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfIndex] += " ";
                }
            }
        }
        else if (heddinResult || heddinIndex) {
            int new_size = vec.size();
            for (int i = 0; i < new_size; i++) {
                vec.at(i).m_var1 = vec.at(i).m_var1 + " " + vec.at(i).m_operator;
                for (int ii = 0; ii < space; ii++) {
                    Input inp = vec.at(i);
                    vec.at(i) = Input(" " + inp.m_var1 + " ",
                        " " + inp.m_operator + " ", ii == 0 ? " = " + inp.m_result + " " : " " + inp.m_result + " ", " " + inp.m_index + " ");
                }
                std::string value = vec.at(i).m_var1;
                if (value.length() > array1[i].length()) {
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                if (heddinResult && array1[sizeOfResult].length() < vec.at(0).m_result.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfResult].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfResult] += " ";
                }
                else if (heddinIndex && array1[sizeOfIndex].length() < vec.at(0).m_index.length() && i + 1 == new_size) {
                    int mySize = vec.at(0).m_result.length() - array1[sizeOfIndex].length();
                    for (int i = 0; i < mySize; i++)
                        array1[sizeOfIndex] += " ";
                }
            }
        }
        else
            for (int i = 0; i < vec.size(); i++) {
                vec.at(i).m_var1 = vec.at(i).m_var1 + " " + vec.at(i).m_operator;
                for (int ii = 0; ii < space; ii++) {
                    Input inp = vec.at(i);
                    vec.at(i) = Input(" " + inp.m_var1 + " ",
                        " " + inp.m_operator + " ", ii == 0 ? " = " + inp.m_result + " " : " " + inp.m_result + " ", " " + inp.m_index + " ");
                }
                std::string value = vec.at(i).m_var1;
                if (value.length() > array1[i].length()) {
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
            }



        std::string my_line = "";
        for (int i = 0; i < array1.size(); i++) {
            my_line += "+";
            for (int ii = 0; ii < array1[i].length(); ii++)
                my_line += "-";

            if (i + 1 == array1.size() && my_line.length() / 2 < temp_title_table) {
                int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                    ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                    temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
                for (int z = 0; z < size; z++) {
                    my_line += "-";
                    array1[array1.size() - 1] += " ";
                }
                my_line += "+\n";
            }
            else if (i + 1 == array1.size()) {
                int temp_size = my_line.size();
                my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
                array1[array1.size() - 1] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
            }
        }



      



        int size = (my_line.length() / 2) - (temp_title_table % 2 ? ((temp_title_table / 2) + 1) : temp_title_table / 2);
        mySpace = temp_title_table == (my_line.length() / 2) || temp_title_table < (my_line.length() / 2) ? size : my_line.length() / 4;









        bool star = temp_title_table > this->language.m_data_title.length() ?
            ((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) % 2 == 1 : true;
        int space_size = temp_title_table > this->language.m_data_title.length() ?
            ((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) % 2 == 0 ?
            (((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) / 2) + (mySpace - 1) :
            (((my_line.length() - (mySpace + this->language.m_data_title.length())) - mySpace) / 2) + mySpace : mySpace;
        int color_message = this->get_color_by_name(this->language.m_color_data_title);
        int color_table = this->get_color_by_name(this->language.m_color_data_table);
        SetConsoleTextAttribute(hConsole, color_message);
        std::string temp = "";
        for (int i = 0; i < space_size; i++)
            temp += " ";
        temp = star ? temp : temp + "*";
        std::cout << temp << this->language.m_data_title << std::endl;
        SetConsoleTextAttribute(hConsole, color_table);



      
        if (this->language.m_center_label) {
            this->my_lable_space = this->get_lable_space(label, my_line, this->language.m_data_title.length());
            this->m_star = this->get_star(label, my_line, this->language.m_data_title.length());
        }





        std::cout << my_line;
        for (int i = 0; i < array1.size(); i++) {
            std::cout << "|" << array1[i];
            if ((i + 1) == array1.size())
                std::cout << "|" << std::endl;
        }
        std::cout << my_line << "|";
        if (heddinResult && heddinIndex) {
            int new_size = vec.size();
            for (int i = 0; i < new_size; i++) {
                Input inp = vec.at(i);
                if (inp.m_var1.length() < array1[i].length()) {
                    int myLen = array1[i].length() - inp.m_var1.length();
                    for (int i = 0; i < myLen; i++)
                        inp.m_var1 += " ";
                }
                std::cout << inp.m_var1 << "|";
                if (i + 1 == new_size) {
                    if (vec.at(0).m_result.length() < array1[sizeOfResult].length()) {
                        int mySize = array1[sizeOfResult].length() - vec.at(0).m_result.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_result += " ";
                    }
                    if (vec.at(0).m_index.length() < array1[sizeOfIndex].length()) {
                        int mySize = array1[sizeOfIndex].length() - vec.at(0).m_index.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_index += " ";
                    }
                    std::cout << vec.at(0).m_result << "|" << vec.at(0).m_index << "|";
                }
            }

        }
        else if (heddinResult || heddinIndex) {
            int new_size = array1.size() - 1;
            for (int i = 0; i < new_size; i++) {
                Input inp = vec.at(i);
                if (inp.m_var1.length() < array1[i].length()) {
                    int myLen = array1[i].length() - inp.m_var1.length();
                    for (int i = 0; i < myLen; i++)
                        inp.m_var1 += " ";
                }
                std::cout << inp.m_var1 << "|";
                if (heddinResult && i + 1 == new_size) {
                    if (vec.at(0).m_result.length() < array1[new_size].length()) {
                        int mySize = array1[new_size].length() - vec.at(0).m_result.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_result += " ";
                    }
                    std::cout << vec.at(0).m_result << "|";
                }
                else if (heddinIndex && i + 1 == new_size) {
                    if (vec.at(0).m_index.length() < array1[new_size].length()) {
                        int mySize = array1[new_size].length() - vec.at(0).m_index.length();
                        for (int i = 0; i < mySize; i++)
                            vec.at(0).m_index += " ";
                    }
                    std::cout << vec.at(0).m_index << "|";
                }
            }
        }
        else
            for (int i = 0; i < array1.size(); i++) {
                Input inp = vec.at(i);
                if (inp.m_var1.length() < array1[i].length()) {
                    int myLen = array1[i].length() - inp.m_var1.length();
                    for (int i = 0; i < myLen; i++)
                        inp.m_var1 += " ";
                }
                std::cout << inp.m_var1 << "|";
            }
        std::cout << std::endl << my_line;
    }
    

  
}

void Tables::show_result_with_operator(std::vector<Input>*vec, std::string table_jop = "", std::string label = "") {
    std::vector<std::string> array1;
    int space = table_jop != "" ? this->language.m_result_space : this->language.m_sugges_space;
    std::string fill = table_jop != "" ? this->language.m_result_fill : this->language.m_sugges_fill;
    bool heddinIndex, heddinResult;
    if (table_jop != "") {
        heddinIndex = this->language.m_heddin_result_address != "on" ? false : true;
        heddinResult = this->language.m_heddin_result != "on" ? false : true;
    }
    else {
        heddinIndex = this->language.m_heddin_sugges_address != "on" ? false : true;
        heddinResult = this->language.m_heddin_sugges_result != "on" ? false : true;
    }
   
    int sizeOfResult = 0, sizeOfIndex = 0;
    std::vector<std::vector<Input>> temp;
    int sizeOfHed = 0;
    std::string title = table_jop != "jop1" ? this->language.m_result_table_suggestion: this->language.m_result_title;
    int color_title   = table_jop != "jop1" ? this->get_color_by_name(this->language.m_color_sugges_title): this->get_color_by_name(this->language.m_color_result_title);
    int color_table   = table_jop != "jop1" ? this->get_color_by_name(this->language.m_color_sugges_table): this->get_color_by_name(this->language.m_color_result_table);
    int temp_title_table;
    if (this->language.m_center_label && table_jop == "jop1")
        temp_title_table = title.length() < label.length() ? label.length() : title.length();
    else
        temp_title_table = title.length();

    if (this->language.m_type_table_operator == "on") {
        if (table_jop == "jop1") {
            for (int i = 0; i < this->myResult.size(); i++) {
                sizeOfHed = this->myResult.at(i).size() > this->myResult.at(sizeOfHed).size() ? i : sizeOfHed;
                for (int z = array1.size() / 2; z < this->myResult.at(sizeOfHed).size(); z++) {
                    std::string var1 = this->language.m_value;
                    std::string op = this->language.m_mark;
                    for (int ii = 0; ii < space; ii++) {
                        var1 = " " + var1 + " ";
                        op = " " + op + " ";
                    }
                    array1.push_back(var1);
                    array1.push_back(op);
                }
                std::vector<Input> v1 = this->myResult.at(i);
                v1.at(0).m_index = std::to_string(this->myResult.size() - i);
                v1.at(v1.size() - 1).m_operator = fill;
                temp.push_back(v1);

                if (i + 1 == this->myResult.size())
                    if (heddinResult && heddinIndex) {
                        array1.push_back(this->language.m_total);
                        array1.push_back(this->language.m_address);
                        sizeOfResult = array1.size() - 2;
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++) {
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                        }
                    }
                    else if (heddinResult) {
                        array1.push_back(this->language.m_total);
                        sizeOfResult = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                    }
                    else if (heddinIndex) {
                        array1.push_back(this->language.m_address);
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    }
            }
        }
        else {
            for (int i = 0; i < this->myResult.size(); i++) {
                std::string inp2 = "";
                for (int ii = 0; ii < (vec->size() > myResult[i].size() ? 0 : vec->size()); ii++) {
                    inp2 += myResult[i].at(ii).m_var1 + (vec->at(ii).m_operator != myResult[i].at(ii).m_operator ? "" : vec->at(ii).m_operator);
                    if (get_text_search(*vec) == inp2) {
                        sizeOfHed = this->myResult.at(i).size() > this->myResult.at(sizeOfHed).size() ? i : sizeOfHed;
                        for (int z = array1.size() / 2; z < this->myResult.at(sizeOfHed).size(); z++) {
                            std::string var1 = this->language.m_value;
                            std::string op = this->language.m_mark;
                            for (int ii = 0; ii < space; ii++) {
                                var1 = " " + var1 + " ";
                                op = " " + op + " ";
                            }
                            array1.push_back(var1);
                            array1.push_back(op);
                        }
                        std::vector<Input> v1 = this->myResult.at(i);
                        v1.at(0).m_index = std::to_string(this->myResult.size() - i);
                        v1.at(v1.size() - 1).m_operator = fill;
                        temp.push_back(v1);
                        break;//for loop
                    }
                }
                if (i + 1 == this->myResult.size())
                    if (heddinResult && heddinIndex) {
                        array1.push_back(this->language.m_total);
                        array1.push_back(this->language.m_address);
                        sizeOfResult = array1.size() - 2;
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++) {
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                        }
                    }
                    else if (heddinResult) {
                        array1.push_back(this->language.m_address);
                        sizeOfResult = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                    }
                    else if (heddinIndex) {
                        array1.push_back(this->language.m_total);
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    }

            }
        }

        if (temp.empty())
            return;








        for (int y = 0; y < temp.size(); y++) {


            if (temp.at(y).size() < this->myResult.at(sizeOfHed).size()) {
                int mySize = this->myResult.at(sizeOfHed).size() - temp.at(y).size();
                for (int ii = 0; ii < mySize; ii++) {
                    temp.at(y).push_back(Input(fill, fill, ""));
                }
            }
            for (int a = 0; a < temp.at(y).size(); a++)
                for (int z = 0; z < space; z++) {
                    Input inp = temp.at(y).at(a);
                    temp.at(y).at(a) = Input(" " + inp.m_var1 + " ",
                        " " + inp.m_operator + " ", " " + inp.m_result + " ", " " + inp.m_index + " ");
                }





            if (heddinResult && heddinIndex)
                for (int i = 0; i < array1.size() - 2; i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0 && temp.at(y).at(0).m_var1.length() > array1[0].length()) {
                        std::string value = temp.at(y).at(i).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else  if (i % 2 == 0 && i > 1 && temp.at(y).at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                        std::string value = temp.at(y).at(index).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else if (i > 0 && temp.at(y).at(index).m_operator.length() > array1[i].length()) {
                        std::string op = temp.at(y).at(index).m_operator;
                        int myLen = op.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }

                    if (array1[sizeOfResult].length() < temp.at(y).at(0).m_result.length() && i + 1 == array1.size() - 2) {
                        int mySize = temp.at(y).at(0).m_result.length() - array1[sizeOfResult].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfResult] += " ";
                    }
                    if (array1[sizeOfIndex].length() < temp.at(y).at(0).m_index.length() && i + 1 == array1.size() - 2) {
                        int mySize = temp.at(y).at(0).m_index.length() - array1[sizeOfIndex].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfIndex] += " ";
                    }

                }

            else if (heddinResult || heddinIndex)
                for (int i = 0; i < array1.size() - 1; i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0 && temp.at(y).at(0).m_var1.length() > array1[0].length()) {
                        std::string value = temp.at(y).at(i).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else  if (i % 2 == 0 && i > 1 && temp.at(y).at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                        std::string value = temp.at(y).at(index).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else if (i > 0 && temp.at(y).at(index).m_operator.length() > array1[i].length()) {
                        std::string op = temp.at(y).at(index).m_operator;
                        int myLen = op.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }

                    if (heddinResult && array1[sizeOfResult].length() < temp.at(y).at(0).m_result.length() && i + 1 == array1.size() - 1) {
                        int mySize = temp.at(y).at(0).m_result.length() - array1[sizeOfResult].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfResult] += " ";
                    }
                    else if (heddinIndex && array1[sizeOfIndex].length() < temp.at(y).at(0).m_index.length() && i + 1 == array1.size() - 1) {
                        int mySize = temp.at(y).at(0).m_index.length() - array1[sizeOfIndex].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfIndex] += " ";
                    }

                }
            else
                for (int i = 0; i < array1.size(); i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0 && temp.at(y).at(0).m_var1.length() > array1[0].length()) {
                        std::string value = temp.at(y).at(i).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else  if (i % 2 == 0 && i > 1 && temp.at(y).at(index).m_var1.length() > array1[i].length()) {//1 - 3 - 5
                        std::string value = temp.at(y).at(index).m_var1;
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    else if (i > 0 && temp.at(y).at(index).m_operator.length() > array1[i].length()) {
                        std::string op = temp.at(y).at(index).m_operator;
                        int myLen = op.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                }

        }

        std::string my_line = "";
        for (int i = 0; i < array1.size(); i++) {
            if (heddinResult && heddinIndex && i + 3 == array1.size())
                continue;
            else if (heddinResult && !heddinIndex && i + 2 == array1.size() || heddinIndex && !heddinResult && i + 2 == array1.size())
                continue;
            else if (i + 1 == array1.size() && !heddinResult && !heddinIndex) {
                if (my_line.length() / 2 < temp_title_table) {
                    int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                        ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                        temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
                    for (int z = 0; z < size; z++) {
                        my_line += "-";
                        array1[array1.size() - 2] += " ";
                    }
                    my_line += "+\n";
                }
                else if (i + 1 == array1.size()) {
                    int temp_size = my_line.size();
                    my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
                    array1[array1.size() - 2] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
                }
                break;
            }


            my_line += "+";
            for (int ii = 0; ii < array1[i].length(); ii++)
                my_line += "-";



            if (i + 1 == array1.size() && my_line.length() / 2 < temp_title_table) {
                int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                    ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                    temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
                for (int z = 0; z < size; z++) {
                    my_line += "-";
                    array1[array1.size() - 1] += " ";
                }
                my_line += "+\n";
            }
            else if (i + 1 == array1.size()) {
                int temp_size = my_line.size();
                my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
                array1[array1.size() - 1] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
            }
        }





        int size = (my_line.length() / 2) - (temp_title_table % 2 ? ((temp_title_table / 2) + 1) : temp_title_table / 2);
        mySpace = temp_title_table == (my_line.length() / 2) || temp_title_table < (my_line.length() / 2) ? size : my_line.length() / 4;








        bool star = temp_title_table > title.length() ?
            ((my_line.length() - (mySpace + title.length())) - mySpace) % 2 == 1 : true;
        int space_size = temp_title_table > title.length() ?
            ((my_line.length() - (mySpace + title.length())) - mySpace) % 2 == 0 ?
            (((my_line.length() - (mySpace + title.length())) - mySpace) / 2) + (mySpace - 1) :
            (((my_line.length() - (mySpace + title.length())) - mySpace) / 2) + mySpace : mySpace;

        SetConsoleTextAttribute(hConsole, color_title);
        std::string space_value = "";
        for (int i = 0; i < space_size; i++)
            space_value += " ";
        space_value = star ? space_value : space_value + "*";
        std::cout << space_value << title << std::endl;
        SetConsoleTextAttribute(hConsole, color_table);

        if (this->language.m_center_label) {
            this->my_lable_space = this->get_lable_space(label, my_line, title.length());
            this->m_star = this->get_star(label, my_line, title.length());
        }



        std::cout << my_line;
        for (int i = 0; i < array1.size(); i++) {
            if (heddinResult && heddinIndex && i + 3 == array1.size()) {
                continue;
            }
            else if (heddinResult && !heddinIndex && i + 2 == array1.size() || heddinIndex && !heddinResult && i + 2 == array1.size())
                continue;
            else if (i + 1 == array1.size() && !heddinResult && !heddinIndex) {
                std::cout << "|" << std::endl;
                break;
            }
            std::cout << "|" << array1[i];
            if (i + 1 == array1.size())
                std::cout << "|" << std::endl;
        }

        std::cout << my_line;

        for (int ii = 0; ii < temp.size(); ii++) {
            std::cout << "|";
            if (heddinResult && heddinIndex) {
                int newSize = array1.size() - 3;
                for (int i = 0; i < newSize; i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0) {
                        Input inp = temp.at(ii).at(i);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i % 2 == 0 && i > 1) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i > 0) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_operator.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_operator.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_operator += " ";
                        }
                        std::cout << inp.m_operator << "|";
                    }
                    if (i + 1 == newSize) {
                        if (temp.at(ii).at(0).m_result.length() < array1[sizeOfResult].length()) {
                            int mySize = array1[sizeOfResult].length() - temp.at(ii).at(0).m_result.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(ii).at(0).m_result += " ";
                        }
                        if (temp.at(ii).at(0).m_index.length() < array1[sizeOfIndex].length()) {
                            int mySize = array1[sizeOfIndex].length() - temp.at(ii).at(0).m_index.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(ii).at(0).m_index += " ";
                        }
                        std::cout << temp.at(ii).at(0).m_result << "|" << temp.at(ii).at(0).m_index << "|";
                    }
                }
            }
            else if (heddinIndex || heddinResult) {
                int newSize = array1.size() - 2;
                for (int i = 0; i < newSize; i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0) {
                        Input inp = temp.at(ii).at(i);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i % 2 == 0 && i > 1) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i > 0) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_operator.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_operator.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_operator += " ";
                        }
                        std::cout << inp.m_operator << "|";
                    }

                    if (heddinResult && i + 1 == newSize) {
                        if (temp.at(ii).at(0).m_result.length() < array1[sizeOfResult].length()) {
                            int mySize = array1[array1.size() - 1].length() - temp.at(ii).at(0).m_result.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(ii).at(0).m_result += " ";
                        }
                        std::cout << temp.at(ii).at(0).m_result << "|";
                    }
                    else if (heddinIndex && i + 1 == newSize) {
                        if (temp.at(ii).at(0).m_index.length() < array1[sizeOfIndex].length()) {
                            int mySize = array1[array1.size() - 1].length() - temp.at(ii).at(0).m_index.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(ii).at(0).m_index += " ";
                        }
                        std::cout << temp.at(ii).at(0).m_index << "|";
                    }
                }

            }
            else
                for (int i = 0; i < array1.size() - 1; i++) {
                    int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
                    if (i == 0) {
                        Input inp = temp.at(ii).at(i);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i % 2 == 0 && i > 1) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_var1.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_var1.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_var1 += " ";
                        }
                        std::cout << inp.m_var1 << "|";
                    }
                    else if (i > 0) {
                        Input inp = temp.at(ii).at(index);
                        if (inp.m_operator.length() < array1[i].length()) {
                            int myLen = array1[i].length() - inp.m_operator.length();
                            for (int i = 0; i < myLen; i++)
                                inp.m_operator += " ";
                        }
                        std::cout << inp.m_operator << "|";
                    }

                }
                std::cout << std::endl << my_line;
        }
    }
    else {

        if (table_jop == "jop1") {// for result
            for (int i = 0; i < this->myResult.size(); i++) {
                sizeOfHed = this->myResult.at(i).size() > this->myResult.at(sizeOfHed).size() ? i : sizeOfHed;
                for (int z = array1.size(); z < this->myResult.at(sizeOfHed).size(); z++) {
                    std::string var1 = this->language.m_value;
                    for (int ii = 0; ii < space; ii++)
                        var1 = " " + var1 + " ";
                    array1.push_back(var1);
                }
                std::vector<Input> v1 = this->myResult.at(i);
                v1.at(0).m_index = std::to_string(this->myResult.size() - i);
                temp.push_back(v1);

                if (i + 1 == this->myResult.size())
                    if (heddinResult && heddinIndex) {
                        array1.push_back(this->language.m_total);
                        array1.push_back(this->language.m_address);
                        sizeOfResult = array1.size() - 2;
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++) {
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                        }
                    }
                    else if (heddinResult) {
                        array1.push_back(this->language.m_total);
                        sizeOfResult = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                    }
                    else if (heddinIndex) {
                        array1.push_back(this->language.m_address);
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    }
            }
        }
        else {
            for (int i = 0; i < this->myResult.size(); i++) {
                std::string inp2 = "";
                for (int ii = 0; ii < (vec->size() > myResult[i].size() ? 0 : vec->size()); ii++) {
                    inp2 += myResult[i].at(ii).m_var1 + (vec->at(ii).m_operator != myResult[i].at(ii).m_operator ? "" : vec->at(ii).m_operator);
                    if (get_text_search(*vec) == inp2) {
                        sizeOfHed = this->myResult.at(i).size() > this->myResult.at(sizeOfHed).size() ? i : sizeOfHed;
                        for (int z = array1.size(); z < this->myResult.at(sizeOfHed).size(); z++) {
                            std::string var1 = this->language.m_value;
                            for (int ii = 0; ii < space; ii++)
                                var1 = " " + var1 + " ";
                            array1.push_back(var1);
                        }
                        std::vector<Input> v1 = this->myResult.at(i);
                        v1.at(0).m_index = std::to_string(this->myResult.size() - i);
                        temp.push_back(v1);
                        break;// for break loop
                    }
                }

                if (i + 1 == this->myResult.size())
                    if (temp.empty())
                        return;
                    else if (heddinResult && heddinIndex) {
                        array1.push_back(this->language.m_total);
                        array1.push_back(this->language.m_address);
                        sizeOfResult = array1.size() - 2;
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++) {
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                        }
                    }
                    else if (heddinResult) {
                        array1.push_back(this->language.m_total);
                        sizeOfResult = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfResult] = " " + array1[sizeOfResult] + " ";
                    }
                    else if (heddinIndex) {
                        array1.push_back(this->language.m_address);
                        sizeOfIndex = array1.size() - 1;
                        for (int ii = 0; ii < space; ii++)
                            array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                    }
            }
        }

        for (int y = 0; y < temp.size(); y++) {
            for (int i = 0; i < temp.at(y).size(); i++) {
                Input inp = temp.at(y).at(i);
                if (i == 0) {
                    std::string myResult = inp.m_result;
                    inp.m_result = "= " + myResult;
                    inp.m_var1 = inp.m_var1 + " " + inp.m_operator;
                }
                else
                    inp.m_var1 = inp.m_var1 + " " + inp.m_operator;
                temp.at(y).at(i) = inp;
            }
            if (temp.at(y).size() < this->myResult.at(sizeOfHed).size()) {
                int mySize = this->myResult.at(sizeOfHed).size() - temp.at(y).size();
                for (int ii = 0; ii < mySize; ii++) {
                    temp.at(y).push_back(Input(fill, fill, ""));
                }
            }
            for (int a = 0; a < temp.at(y).size(); a++)
                for (int z = 0; z < space; z++) {
                    Input inp = temp.at(y).at(a);
                    temp.at(y).at(a) = Input(" " + inp.m_var1 + " ",
                        inp.m_operator, " " + inp.m_result + " ", " " + inp.m_index + " ");
                }

            if (heddinResult && heddinIndex)
                for (int i = 0; i < temp.at(y).size(); i++) {
                    std::string value = temp.at(y).at(i).m_var1;
                    if (value.length() > array1[i].length()) {
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }

                    if (array1[sizeOfResult].length() < temp.at(y).at(0).m_result.length() && i + 1 == temp.at(y).size()) {
                        int mySize = temp.at(y).at(0).m_result.length() - array1[sizeOfResult].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfResult] += " ";
                    }
                    if (array1[sizeOfIndex].length() < temp.at(y).at(0).m_index.length() && i + 1 == temp.at(y).size()) {
                        int mySize = temp.at(y).at(0).m_index.length() - array1[sizeOfIndex].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfIndex] += " ";
                    }
                }
            else if (heddinResult || heddinIndex)
                for (int i = 0; i < temp.at(y).size(); i++) {
                    std::string value = temp.at(y).at(i).m_var1;
                    if (value.length() > array1[i].length()) {
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                    if (heddinResult && array1[sizeOfResult].length() < temp.at(y).at(0).m_result.length() && i + 1 == temp.at(y).size()) {
                        int mySize = temp.at(y).at(0).m_result.length() - array1[sizeOfResult].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfResult] += " ";
                    }
                    else if (heddinIndex && array1[sizeOfIndex].length() < temp.at(y).at(0).m_index.length() && i + 1 == temp.at(y).size()) {
                        int mySize = temp.at(y).at(0).m_index.length() - array1[sizeOfIndex].length();
                        for (int z = 0; z < mySize; z++)
                            array1[sizeOfIndex] += " ";
                    }
                }
            else
                for (int i = 0; i < temp.at(y).size(); i++) {
                    std::string value = temp.at(y).at(i).m_var1;
                    if (value.length() > array1[i].length()) {
                        int myLen = value.length() - array1[i].length();
                        for (int ii = 0; ii < myLen; ii++)
                            array1[i] += " ";
                    }
                }
        }


        std::string my_line = "";
        for (int i = 0; i < array1.size(); i++) {
            my_line += "+";
            for (int ii = 0; ii < array1[i].length(); ii++)
                my_line += "-";
            if (i + 1 == array1.size() && my_line.length() / 2 < temp_title_table) {
                int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                    ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                    temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
                for (int z = 0; z < size; z++) {
                    my_line += "-";
                    array1[array1.size() - 1] += " ";
                }
                my_line += "+\n";
            }
            else if (i + 1 == array1.size()) {
                int temp_size = my_line.size();
                my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
                array1[array1.size() - 1] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
            }
        }


       

        int size = (my_line.length() / 2) - (temp_title_table % 2 ? ((temp_title_table / 2) + 1) : temp_title_table / 2);
        mySpace = temp_title_table == (my_line.length() / 2) || temp_title_table < (my_line.length() / 2) ? size : my_line.length() / 4;




        bool star = temp_title_table > title.length() ?
            ((my_line.length() - (mySpace + title.length())) - mySpace) % 2 == 1 : true;
        int space_size = temp_title_table > title.length() ?
            ((my_line.length() - (mySpace + title.length())) - mySpace) % 2 == 0 ?
            (((my_line.length() - (mySpace + title.length())) - mySpace) / 2) + (mySpace - 1) :
            (((my_line.length() - (mySpace + title.length())) - mySpace) / 2) + mySpace : mySpace;

        SetConsoleTextAttribute(hConsole, color_title);
        std::string space_value = "";
        for (int i = 0; i < space_size; i++)
            space_value += " ";
        space_value = star ? space_value : space_value + "*";
        std::cout << space_value << title << std::endl;
        SetConsoleTextAttribute(hConsole, color_table);

        if (this->language.m_center_label) {
            this->my_lable_space = this->get_lable_space(label, my_line, title.length());
            this->m_star = this->get_star(label, my_line, title.length());
        }


        std::cout << my_line;
        for (int i = 0; i < array1.size(); i++) {
            std::cout << "|" << array1[i];
            if (i + 1 == array1.size())
                std::cout << "|" << std::endl;
        }
        std::cout << my_line;
        for (int y = 0; y < temp.size(); y++) {
            std::cout << "|";
            if (heddinResult && heddinIndex) {
                for (int i = 0; i < temp.at(y).size(); i++) {
                    Input inp = temp.at(y).at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";

                    if (i + 1 == temp.at(y).size()) {
                        if (temp.at(y).at(0).m_result.length() < array1[sizeOfResult].length()) {
                            int mySize = array1[sizeOfResult].length() - temp.at(y).at(0).m_result.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(y).at(0).m_result += " ";
                        }
                        if (temp.at(y).at(0).m_index.length() < array1[sizeOfIndex].length()) {
                            int mySize = array1[sizeOfIndex].length() - temp.at(y).at(0).m_index.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(y).at(0).m_index += " ";
                        }
                        std::cout << temp.at(y).at(0).m_result << "|" << temp.at(y).at(0).m_index << "|";
                    }
                }
            }
            else if (heddinResult || heddinIndex) {
                for (int i = 0; i < temp.at(y).size(); i++) {
                    Input inp = temp.at(y).at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                    if (heddinResult && i + 1 == temp.at(y).size()) {
                        if (temp.at(y).at(0).m_result.length() < array1[sizeOfResult].length()) {
                            int mySize = array1[sizeOfResult].length() - temp.at(y).at(0).m_result.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(y).at(0).m_result += " ";
                        }
                        std::cout << temp.at(y).at(0).m_result << "|";
                    }
                    else if (heddinIndex && i + 1 == temp.at(y).size()) {
                        if (temp.at(y).at(0).m_index.length() < array1[sizeOfIndex].length()) {
                            int mySize = array1[sizeOfIndex].length() - temp.at(y).at(0).m_index.length();
                            for (int i = 0; i < mySize; i++)
                                temp.at(y).at(0).m_index += " ";
                        }
                        std::cout << temp.at(y).at(0).m_index << "|";
                    }
                }
            }
            else
                for (int i = 0; i < temp.at(y).size(); i++) {
                    Input inp = temp.at(y).at(i);
                    if (inp.m_var1.length() < array1[i].length()) {
                        int myLen = array1[i].length() - inp.m_var1.length();
                        for (int i = 0; i < myLen; i++)
                            inp.m_var1 += " ";
                    }
                    std::cout << inp.m_var1 << "|";
                }

            std::cout << std::endl << my_line;
        }

    }

}

void Tables::display_table_menu(std::vector<std::vector<std::string>> vec, std::string word, std::string label, MenuEdit section) {
    std::string id = word;
    std::vector<std::string> array1;
    int space = this->language.m_menu_space;
    bool heddinIndex = this->language.m_heddin_menu_address != "on" ? false : true;
    int sizeOfIndex = 0;

    array1 = { this->language.m_app };
    for (int i = 0; i < array1.size(); i++) {
        for (int y = 0; y < space; y++)
            array1[i] = " " + array1[i] + " ";
        if (i + 1 == array1.size()) {
            if (heddinIndex) {
                array1.push_back(this->language.m_app_address);
                sizeOfIndex = array1.size() - 1;
                for (int y = 0; y < space; y++)
                    array1[sizeOfIndex] = " " + array1[sizeOfIndex] + " ";
                for (int z = 0; z < vec.size(); z++) {
                    if (vec[z][1] == word)
                        word = std::to_string(z);
                    vec[z] = { vec[z][0], std::to_string(z + 1) };
                }
            }
            else
                for (int z = 0; z < vec.size(); z++) {
                    if (vec[z][1] == word)
                        word = std::to_string(z);
                    vec[z] = { vec[z][0] };
                }
            break;
        }
    }

    for (int y = 0; y < vec.size(); y++) {
        for (int a = 0; a < vec.at(y).size(); a++)
            for (int z = 0; z < space; z++) {
                vec[y][a] = " " + vec[y][a] + " ";
            }
        if (heddinIndex)
            for (int i = 0; i < vec.at(y).size(); i++) {
                std::string value = vec.at(y).at(i);
                if (value.length() > array1[i].length()) {
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
                if (array1[sizeOfIndex].length() < vec.at(y).at(vec[y].size() - 1).length() && i + 1 == vec.at(y).size()) {
                    int mySize = vec.at(y).at(vec[y].size() - 1).length() - array1[sizeOfIndex].length();
                    for (int z = 0; z < mySize; z++)
                        array1[sizeOfIndex] += " ";
                }
            }
        else
            for (int i = 0; i < vec.at(y).size(); i++) {
                std::string value = vec.at(y).at(i);
                if (value.length() > array1[i].length()) {
                    int myLen = value.length() - array1[i].length();
                    for (int ii = 0; ii < myLen; ii++)
                        array1[i] += " ";
                }
            }
    }


    int temp_title_table;
    if (this->language.m_center_label)
        temp_title_table = this->language.get_m_menu_title(section).length() < label.length() ? label.length() : this->language.get_m_menu_title(section).length();
    else
        temp_title_table = this->language.get_m_menu_title(section).length();

    std::string my_line = "";
    for (int i = 0; i < array1.size(); i++) {
        my_line += "+";
        for (int ii = 0; ii < array1[i].length(); ii++)
            my_line += "-";
        if (i + 1 == array1.size() && my_line.length() / 2 < temp_title_table) {
            int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
            for (int z = 0; z < size; z++) {
                my_line += "-";
                array1[array1.size() - 1] += " ";
            }
            my_line += "+\n";
        }
        else if (i + 1 == array1.size()) {
            int temp_size = my_line.size();
            my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? "-+\n" : "+\n" : temp_title_table % 2 == 1 ? "+\n" : "-+\n";
            array1[array1.size() - 1] += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
        }
    }




    int size = (my_line.length() / 2) - (temp_title_table % 2 ? ((temp_title_table / 2) + 1) : temp_title_table / 2);
    mySpace = temp_title_table == (my_line.length() / 2) || temp_title_table < (my_line.length() / 2) ? size : my_line.length() / 4;




    bool star = temp_title_table > this->language.get_m_menu_title(section).length() ?
        ((my_line.length() - (mySpace + this->language.get_m_menu_title(section).length())) - mySpace) % 2 == 1 : true;
    int space_size = temp_title_table > this->language.get_m_menu_title(section).length() ?
        ((my_line.length() - (mySpace + this->language.get_m_menu_title(section).length())) - mySpace) % 2 == 0 ?
        (((my_line.length() - (mySpace + this->language.get_m_menu_title(section).length())) - mySpace) / 2) + (mySpace - 1) :
        (((my_line.length() - (mySpace + this->language.get_m_menu_title(section).length())) - mySpace) / 2) + mySpace : mySpace;
    int color_title = this->get_color_by_name(this->language.m_color_menu_title);
    int color_table = this->get_color_by_name(this->language.m_color_menu_table);
    SetConsoleTextAttribute(hConsole, color_title);
    std::string temp = "";
    for (int i = 0; i < space_size; i++)
        temp += " ";
    temp = star ? temp : temp + "*";
    std::cout << temp << this->language.get_m_menu_title(section) << std::endl;
    SetConsoleTextAttribute(hConsole, color_table);

    if (this->language.m_center_label) {
        this->my_lable_space = this->get_lable_space(label, my_line, this->language.get_m_menu_title(section).length());
        this->m_star = this->get_star(label, my_line, this->language.get_m_menu_title(section).length());
    }



    std::cout << my_line;
    for (int i = 0; i < array1.size(); i++) {
        std::cout << "|" << array1[i];
        if (i + 1 == array1.size())
            std::cout << "|" << std::endl;
    }


    
    std::cout << my_line;

    for (int y = 0; y < vec.size(); y++) {

        if (word == std::to_string(y)) {
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->language.m_color_select));
            std::cout << "|";
            SetConsoleTextAttribute(hConsole, color_table);
        }
        else
            std::cout << "|";

        if (heddinIndex) {
            for (int i = 0; i < vec.at(y).size(); i++) {
                std::string value = vec.at(y).at(i);
                if (value.length() < array1[i].length()) {
                    int myLen = array1[i].length() - value.length();
                    for (int i = 0; i < myLen; i++)
                        value += " ";
                }
                if (vec.at(y).at(sizeOfIndex).length() < array1[sizeOfIndex].length() && i + 1 == vec[y].size()) {
                    int mySize = array1[sizeOfIndex].length() - vec.at(y).at(sizeOfIndex).length();
                    for (int i = 0; i < mySize; i++)
                        vec.at(y).at(sizeOfIndex) += " ";
                }



                if (i + 1 == vec[y].size() && word == std::to_string(y)) {
                    SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->language.m_color_select));
                    std::cout << vec.at(y).at(sizeOfIndex) << "|";
                    SetConsoleTextAttribute(hConsole, color_table);
                }
                else if (i + 1 == vec[y].size())
                    std::cout << vec.at(y).at(sizeOfIndex) << "|";


                else if (word == std::to_string(y)) {
                    SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->language.m_color_select));
                    std::cout << value << "|";
                    SetConsoleTextAttribute(hConsole, color_table);
                }
                else
                    std::cout << value << "|";
            }
        }
        else
            for (int i = 0; i < vec.at(y).size(); i++) {
                std::string value = vec.at(y).at(i);
                if (value.length() < array1[i].length()) {
                    int myLen = array1[i].length() - value.length();
                    for (int i = 0; i < myLen; i++)
                        value += " ";
                }
                if (word == std::to_string(y)) {
                    SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->language.m_color_select));
                    std::cout << value << "|";
                    SetConsoleTextAttribute(hConsole, color_table);
                }
                else
                    std::cout << value << "|";
            }


        if (word == std::to_string(y + 1) || word == std::to_string(y)) {
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->language.m_color_select));
            std::cout << std::endl << my_line;
            SetConsoleTextAttribute(hConsole, color_table);
        }
        else
            std::cout << std::endl << my_line;
    }
}

int Tables::get_lable_space(std::string label, std::string my_line, int title) {
    return label.length() < title ?
        ((my_line.length() - (this->mySpace * 2)) - label.length()) % 2 == 1 ?
        (((my_line.length() - (this->mySpace * 2)) - label.length()) / 2) + mySpace :
        ((((my_line.length() - (this->mySpace * 2)) - label.length()) / 2) - 1) + mySpace : this->mySpace;   
}

bool Tables::get_star(std::string label, std::string my_line, int title) {
    return label.length() < title ?
        ((my_line.length() - (mySpace * 2)) - label.length()) % 2 == 1 : true;
}










