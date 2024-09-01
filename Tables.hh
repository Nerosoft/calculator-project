class Tables : public Language {
public:
    HANDLE hConsole;
    int mySpace = 0;
    int my_lable_space = 0;
    bool m_star;
    Tables();
    void tableResult77(std::vector<Input> vec, std::string label);
    void table_confirm(std::vector<Input> vec, std::string label);
    void table_delete(std::vector<Input> vec, std::string label);
    void table_display(std::vector<Input> vec, std::string label);
    void show_result_with_operator(std::vector<Input> vec, std::string table_jop, std::string label);
    void display_table_menu(std::vector<std::vector<std::string>> vec, std::string word, std::string label, std::string title_menu);
   
    int get_lable_space(std::string label, std::string my_line, int title);
    bool get_star(std::string label, std::string my_line, int title);

    void get_culc_Result();
    int get_color_by_name(std::string color_name);
    std::string get_text_search(std::vector <Input> vec);

private:
    std::string trim(const std::string& source);
    std::vector<std::vector<Input>> init_result_auto_compleat(std::vector<Input>vec, std::string jop, int* sizeOfHed, std::vector<std::string>* array1);
    void set_total_address(int space, bool state_pop, bool heddinResult, bool heddinIndex, std::vector<std::string>* array1, std::string fill, std::vector<std::vector<Input>>* temp, int sizeOfHed);
    std::string print_title(std::string m_line, std::vector<std::string>* array1, std::string dismiss_line, int temp_title_table, std::string table_jop, std::string title, int color_title, int color_table, std::string label);
    void print_heder_table(std::vector<std::string>array1, bool heddinIndex, bool heddinResult, std::string dismiss_word, int color_address, int color_total, int color_operator, int color_value, int color_table);
    void print_body(std::string my_line, std::vector<std::vector<Input>>temp, bool heddinResult, std::string dismiss_word, std::vector<std::string>array1);
    bool get_total_address(std::string value);
    void print_body_test(bool state, std::string my_line, std::vector<std::string>array1, std::vector<Input> vec, bool heddinResult, std::string dismiss_word);
    void int_tables(bool state, std::vector<Input>* vec, std::vector<std::string>* array1, int* sizeOfHed,
        bool heddinIndex, bool heddinResult, int space, std::string fill, std::string index);
};

void Tables::int_tables(bool state, std::vector<Input>* vec, std::vector<std::string>* array1, int* sizeOfHed,bool heddinIndex, bool heddinResult, int space, std::string fill, std::string index) {
    int size_loop = state && heddinIndex || state && heddinResult ? vec->size() + 1 : vec->size();
    for (int z = 0; z < size_loop; z++) {
        int size_array = this->m_type_table_operator == "on" ? (array1->size() / 2) : array1->size();
        int size_item = sizeOfHed != nullptr ? this->myResult.at(*sizeOfHed).size() : 0;
        const int my_size = !state && size_array < size_item ? size_item - size_array : state ? 1 : 0;
        for (int i = 0; i < my_size; i++)
            if (this->m_type_table_operator != "on" && !state || !this->get_total_address(this->m_type_table_operator) && z < vec->size() && state || z < vec->size() && z + 1 == vec->size() && vec->at(vec->size() - 1).m_operator == "" && state)//condtion
                array1->push_back(this->m_value);
            else if (z == vec->size() && heddinIndex && heddinResult) {
                array1->push_back(this->m_total);
                array1->push_back(this->m_address);
            }
            else if (z == vec->size() && heddinResult || z == vec->size() && heddinIndex)
                array1->push_back(heddinResult ? this->m_total : this->m_address);
            else {
                array1->push_back(this->m_value);
                array1->push_back(this->m_mark);
            }

        for (int a = 0; a < space; a++) {
            if (!state && size_array < size_item)
                for (int i = 1; i <= (this->m_type_table_operator != "on" ? (this->myResult.at(*sizeOfHed).size() - size_array) : ((this->myResult.at(*sizeOfHed).size() - size_array) * 2)); i++)
                    array1->at(array1->size() - i) = " " + array1->at(array1->size() - i) + " ";

            if (!state) {
                vec->at(z) = this->m_type_table_operator == "on" ?
                    Input(" " + vec->at(z).m_var1 + " ", " " + (vec->at(z).m_operator != "" ? vec->at(z).m_operator : fill) + " ", " " + vec->at(z).m_result + " ", " " + (a == 0 ? index : vec->at(z).m_index) + " ") :
                    Input(" " + (a == 0 ? vec->at(z).m_var1 + " " + vec->at(z).m_operator : vec->at(z).m_var1) + " ", " " + vec->at(z).m_operator + " ", " " + (a == 0 ? "= " + vec->at(z).m_result : vec->at(z).m_result) + " ", " " + (a == 0 ? index : vec->at(z).m_index) + " ");

            }
            else if (!this->get_total_address(this->m_type_table_operator) && z < vec->size() || z < vec->size() && z + 1 == vec->size() && trim(vec->at(vec->size() - 1).m_operator) == "") {
                array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
                vec->at(z) = this->get_total_address(this->m_type_table_operator) ?
                    Input(" " + vec->at(z).m_var1 + " ", " " + vec->at(z).m_operator + " ", " " + vec->at(z).m_result + " ", " " + vec->at(z).m_index + " ") :
                    Input(" " + (a == 0 ? vec->at(z).m_var1 + " " + vec->at(z).m_operator : vec->at(z).m_var1) + " ", "", " " + (a == 0 ? "= " + vec->at(z).m_result : vec->at(z).m_result) + " ", " " + vec->at(z).m_index + " ");

            }
            else if (z < vec->size()) {
                array1->at(array1->size() - 2) = " " + array1->at(array1->size() - 2) + " ";
                array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
                vec->at(z) = Input(" " + vec->at(z).m_var1 + " ", " " + vec->at(z).m_operator + " ", " " + vec->at(z).m_result + " ", " " + vec->at(z).m_index + " ");
            }
            else if (heddinIndex && heddinResult) {
                array1->at(array1->size() - 2) = " " + array1->at(array1->size() - 2) + " ";
                array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
            }
            else
                array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
        }


        if (state && z < vec->size()) {//using if else her important
            if (z + 1 == vec->size() && trim(vec->at(vec->size() - 1).m_operator) == "" && this->get_total_address(this->m_type_table_operator) || vec->at(z).m_operator.length() > array1->at(array1->size() - 1).length() && this->get_total_address(this->m_type_table_operator)) {
                int myLen = (z + 1 == vec->size() && trim(vec->at(vec->size() - 1).m_operator) == "" ? vec->at(vec->size() - 1).m_var1.length() : vec->at(z).m_operator.length()) - array1->at(array1->size() - 1).length();
                for (int ii = 0; ii < myLen; ii++)
                    array1->at(array1->size() - 1) += " ";
            }
            if (vec->at(z).m_var1.length() > array1->at(this->get_total_address(this->m_type_table_operator) ? array1->size() == 1 ? array1->size() - 1 : array1->size() - 2 : z).length()) {
                int myLen = vec->at(z).m_var1.length() - array1->at(this->get_total_address(this->m_type_table_operator) ? array1->size() == 1 ? array1->size() - 1 : array1->size() - 2 : z).length();
                for (int ii = 0; ii < myLen; ii++)
                    array1->at(this->get_total_address(this->m_type_table_operator) ? array1->size() == 1 ? array1->size() - 1 : array1->size() - 2 : z) += " ";
            }
        }
        else if (state)
            for (int i = 0; i < (heddinResult && heddinIndex ? 2 : 1); i++) {//user if her
                int myLen = i == 0 && heddinResult && heddinIndex ? vec->at(0).m_result.length() - array1->at(array1->size() - 2).length() : heddinIndex ? vec->at(0).m_index.length() - array1->at(array1->size() - 1).length() : vec->at(0).m_result.length() - array1->at(array1->size() - 1).length();
                for (int ii = 0; ii < myLen; ii++)
                    array1->at(heddinResult && heddinIndex && i == 0 ? array1->size() - 2 : array1->size() - 1) += " ";
            }

    }
}
std::string Tables::trim(const std::string& source) {
    std::string s(source);
    s.erase(0, s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    return s;
}
std::vector<std::vector<Input>> Tables::init_result_auto_compleat(std::vector<Input>vec, std::string jop, int* sizeOfHed, std::vector<std::string>* array1) {
    std::vector<std::vector<Input>> temp;
    int space = jop != "" ? this->m_result_space : this->m_sugges_space;
    std::string fill = jop != "" ? this->m_result_fill : this->m_sugges_fill;
    for (int i = 0; i < this->myResult.size(); i++) {
        std::vector<Input>inp = this->myResult.at(i);
        if (jop == "jop1") {
            *sizeOfHed = this->myResult.at(i).size() > this->myResult.at(*sizeOfHed).size() ? i : *sizeOfHed;
            this->int_tables(false, &inp, array1, sizeOfHed, false, false, space, fill, std::to_string(this->myResult.size() - i));
            temp.push_back(inp);
        }
        else {
            std::string inp2 = "";
            for (int y = 0; y < (vec.size() > this->myResult[i].size() ? 0 : vec.size()); y++) {
                inp2 += myResult[i].at(y).m_var1 + (vec.at(y).m_operator != myResult[i].at(y).m_operator ? "" : vec.at(y).m_operator);
                if (this->get_text_search(vec) == inp2) {
                    *sizeOfHed = this->myResult.at(i).size() > this->myResult.at(*sizeOfHed).size() ? i : *sizeOfHed;
                    this->int_tables(false, &inp, array1, sizeOfHed, false, false, space, fill, std::to_string(this->myResult.size() - i));
                    temp.push_back(inp);
                    break;
                }
            }
        }
    }
    return temp;
}
void Tables::set_total_address(int space, bool state_pop, bool heddinResult, bool heddinIndex, std::vector<std::string>* array1, std::string fill, std::vector<std::vector<Input>>* temp, int sizeOfHed) {
    if (state_pop)
        array1->pop_back();
    if (heddinIndex && heddinResult) {
        array1->push_back(this->m_total);
        array1->push_back(this->m_address);
        for (int ii = 0; ii < space; ii++) {
            array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
            array1->at(array1->size() - 2) = " " + array1->at(array1->size() - 2) + " ";
            fill = " " + fill + " ";
        }
    }
    else if (heddinIndex || heddinResult) {
        array1->push_back(heddinResult ? this->m_total : this->m_address);
        for (int ii = 0; ii < space; ii++) {
            array1->at(array1->size() - 1) = " " + array1->at(array1->size() - 1) + " ";
            fill = " " + fill + " ";
        }
    }else
        for (int z = 0; z < space; z++)
            fill = " " + fill + " ";
    for (int y = 0; y < temp->size(); y++) {
        if (temp->at(y).size() < this->myResult.at(sizeOfHed).size()) {
            int mySize = this->myResult.at(sizeOfHed).size() - temp->at(y).size();
            for (int ii = 0; ii < mySize; ii++)
                temp->at(y).push_back(Input(fill, fill, ""));
        }
        for (int i = 0; i < array1->size(); i++) {
            int index = ((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2);
            std::string value = this->m_type_table_operator == "on" ?
                i < ((temp->at(y).size() * 2) - 1) ? i == 0 || i % 2 == 0 && i > 1 ? temp->at(y).at(index).m_var1 : temp->at(y).at(index).m_operator : heddinResult && index == temp->at(y).size() - 1 ? temp->at(y).at(0).m_result : temp->at(y).at(0).m_index :
                //-------------------------------------------------------------------------------------------------------------------------------------
                i < temp->at(y).size() ? temp->at(y)[i].m_var1 : heddinResult && i == temp->at(y).size() ? temp->at(y)[0].m_result : temp->at(y)[0].m_index;
            if (value.length() > array1->at(i).length()) {
                int myLen = value.length() - array1->at(i).length();
                for (int ii = 0; ii < myLen; ii++)
                    array1->at(i) += " ";
            }
        }
    }

}
std::string Tables::print_title(std::string m_line, std::vector<std::string>* array1, std::string dismiss_line, int temp_title_table, std::string table_jop, std::string title, int color_title, int color_table, std::string label) {
    std::string my_line = "";
    for (int i = 0; i < array1->size(); i++) {
        my_line += dismiss_line;
        for (int ii = 0; ii < array1->at(i).length(); ii++)
            my_line += m_line;
        if (i + 1 == array1->size() && my_line.length() / 2 < temp_title_table) {
            int size = size = my_line.length() % 2 == 1 ? temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 2 :
                ((temp_title_table - (my_line.length() / 2)) * 2) - 1 :
                temp_title_table % 2 == 0 ? ((temp_title_table - (my_line.length() / 2)) * 2) - 1 : ((temp_title_table - (my_line.length() / 2)) * 2) - 2;
            for (int z = 0; z < size; z++) {
                my_line += m_line;
                array1->at(array1->size() - 1) += " ";
            }
            my_line += dismiss_line + "\n";
        }
        else if (i + 1 == array1->size()) {
            int temp_size = my_line.size();
            my_line += my_line.length() % 2 == 1 ? temp_title_table % 2 == 1 ? m_line + dismiss_line + "\n" : dismiss_line + "\n" : temp_title_table % 2 == 1 ? dismiss_line + "\n" : m_line + dismiss_line + "\n";
            array1->at(array1->size() - 1) += temp_size % 2 == 1 ? temp_title_table % 2 == 1 ? " " : "" : temp_title_table % 2 == 1 ? "" : " ";
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
    if (this->m_center_label && table_jop == "jop1") {
        this->my_lable_space = this->get_lable_space(label, my_line, title.length());
        this->m_star = this->get_star(label, my_line, title.length());
    }
    return my_line;
}
void Tables::print_heder_table(std::vector<std::string>array1, bool heddinIndex, bool heddinResult, std::string dismiss_word, int color_address, int color_total, int color_operator, int color_value, int color_table) {
    for (int i = 0; i < array1.size(); i++) {
        std::cout << dismiss_word;
        if (heddinIndex && heddinResult && i + 2 == array1.size() ||
            heddinIndex && heddinResult && i + 1 == array1.size() ||
            heddinIndex && i + 1 == array1.size() ||
            heddinResult && i + 1 == array1.size())
            SetConsoleTextAttribute(hConsole, heddinIndex && i + 1 == array1.size() ? color_address : color_total);
        else
            SetConsoleTextAttribute(hConsole, this->m_type_table_operator == "on" && i % 2 ? color_operator : color_value);
        std::cout << array1[i];
        SetConsoleTextAttribute(hConsole, color_table);
        if (i + 1 == array1.size())
            std::cout << dismiss_word << std::endl;
    }
}
void Tables::print_body(std::string my_line, std::vector<std::vector<Input>>temp, bool heddinResult, std::string dismiss_word, std::vector<std::string>array1) {
    std::cout << my_line;
    for (int ii = 0; ii < temp.size(); ii++)
        this->print_body_test(false, my_line, array1, temp[ii], heddinResult, dismiss_word);
}
bool Tables::get_total_address(std::string value) {
    return value != "on" ? false : true;
}
void Tables::print_body_test(bool state, std::string my_line, std::vector<std::string>array1, std::vector<Input> vec, bool heddinResult, std::string dismiss_word) {
    if (state)
        std::cout << my_line << dismiss_word;
    else
        std::cout << dismiss_word;
    for (int i = 0; i < array1.size(); i++) {
        std::string value = state ?
            this->m_type_table_operator != "on" ?
            i < vec.size() ? vec.at(i).m_var1 : heddinResult && i == vec.size() ? vec.at(0).m_result : vec.at(0).m_index :
            //----------------------------------------------------------------------------------------------------------------
            i < (trim(vec[vec.size() - 1].m_operator) == "" ? ((vec.size() * 2) - 1) : (vec.size() * 2)) ? i == 0 || i % 2 == 0 && i > 1 ? vec.at(((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2)).m_var1 : vec.at(((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2)).m_operator : heddinResult && i == (trim(vec[vec.size() - 1].m_operator) == "" ? ((vec.size() * 2) - 1) : (vec.size() * 2)) ? vec.at(0).m_result : vec.at(0).m_index :
            //---------------------------------------------------------------------------------------
            this->m_type_table_operator != "on" ? i < vec.size() ? vec.at(i).m_var1 : heddinResult && i == vec.size() ? vec[0].m_result : vec[0].m_index :
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            i < ((vec.size() * 2) - 1) ? i == 0 || i % 2 == 0 && i > 1 ? vec.at((((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2))).m_var1 : vec.at((((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2))).m_operator : heddinResult && (((i + 1) + (i / 2) * 2) - (i + 1) - (i / 2)) == vec.size() - 1 ? vec.at(0).m_result : vec.at(0).m_index;
        if (array1[i].length() > value.length()) {
            int mySize = array1[i].length() - value.length();
            for (int i = 0; i < mySize; i++)
                value += " ";
        }
        std::cout << value << dismiss_word;
    }
    std::cout << std::endl << my_line;
}



Tables::Tables(){
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
 



void Tables::table_display(std::vector<Input> vec, std::string label) {
    std::vector<std::string> array1;
    this->int_tables(true, &vec, &array1, nullptr, this->get_total_address(this->m_heddin_display_address), this->get_total_address(this->m_heddin_display_result), this->m_display_space, "", "");
    std::string my_line = this->print_title(this->m_line_display, &array1, this->m_dismiss_line_display, this->m_center_label && this->m_display_title.length() < label.length() ? label.length() : this->m_display_title.length(), "jop1", this->m_display_title, this->get_color_by_name(this->m_color_display_title), this->get_color_by_name(this->m_color_display_table), label);
    std::cout << my_line;
    this->print_heder_table(array1,
        this->get_total_address(this->m_heddin_display_address),
        this->get_total_address(this->m_heddin_display_result),
        this->m_dismiss_word_display,
        this->get_color_by_name(this->m_color_address_display),
        this->get_color_by_name(this->m_color_total_display),
        this->m_type_table_operator != "on" ? 0 : this->get_color_by_name(this->m_color_operator_display),
        this->get_color_by_name(this->m_color_value_display),
        this->get_color_by_name(this->m_color_display_table));

    this->print_body_test(true, my_line, array1, vec,
        this->get_total_address(this->m_heddin_display_result),
        this->m_dismiss_word_display);
}

void Tables::table_delete(std::vector<Input> vec, std::string label) {
    std::vector<std::string> array1;
    this->int_tables(true, &vec, &array1, nullptr, this->get_total_address(this->m_heddin_delete_address), this->get_total_address(this->m_heddin_delete_result), this->m_delete_space, "", "");
    std::string my_line = this->print_title(this->m_line_delete, &array1, this->m_dismiss_line_delete, this->m_center_label && this->m_delete_title.length() < label.length() ? label.length() : this->m_delete_title.length(), "jop1", this->m_delete_title, this->get_color_by_name(this->m_color_delete_title), this->get_color_by_name(this->m_color_delete_table), label);
    std::cout << my_line;
    this->print_heder_table(array1,
        this->get_total_address(this->m_heddin_delete_address),
        this->get_total_address(this->m_heddin_delete_result),
        this->m_dismiss_word_delete,
        this->get_color_by_name(this->m_color_address_delete),
        this->get_color_by_name(this->m_color_total_delete),
        this->m_type_table_operator != "on" ? 0 : this->get_color_by_name(this->m_color_operator_delete),
        this->get_color_by_name(this->m_color_value_delete),
        this->get_color_by_name(this->m_color_delete_table));

    this->print_body_test(true, my_line, array1, vec,
        this->get_total_address(this->m_heddin_delete_result),
        this->m_dismiss_word_delete);
}


void Tables::table_confirm(std::vector<Input> vec, std::string label) {
    std::vector<std::string> array1;
    this->int_tables(true, &vec, &array1, nullptr, this->get_total_address(this->m_heddin_confirm_address), this->get_total_address(this->m_heddin_confirm_result), this->m_confirm_space, "", "");
    std::string my_line = this->print_title(this->m_line_confirm, &array1, this->m_dismiss_line_confirm, this->m_center_label && this->m_confirm_title.length() < label.length() ? label.length() : this->m_confirm_title.length(), "jop1", this->m_confirm_title, this->get_color_by_name(this->m_color_confirm_title), this->get_color_by_name(this->m_color_confirm_table), label);
    std::cout << my_line;
    this->print_heder_table(array1,
        this->get_total_address(this->m_heddin_confirm_address),
        this->get_total_address(this->m_heddin_confirm_result),
        this->m_dismiss_word_confirm,
        this->get_color_by_name(this->m_color_address_confirm),
        this->get_color_by_name(this->m_color_total_confirm),
        this->m_type_table_operator != "on" ? 0 : this->get_color_by_name(this->m_color_operator_confirm),
        this->get_color_by_name(this->m_color_value_confirm),
        this->get_color_by_name(this->m_color_confirm_table));

    this->print_body_test(true, my_line, array1, vec,
        this->get_total_address(this->m_heddin_confirm_result),
        this->m_dismiss_word_confirm);
}

void Tables::tableResult77(std::vector<Input> vec, std::string label) {
    std::vector<std::string> array1;    
    this->int_tables(true, &vec, &array1, nullptr, this->get_total_address(this->m_heddin_data_address), this->get_total_address(this->m_heddin_data_result), this->m_data_space,"","");
    std::string my_line = this->print_title(this->m_line_data, &array1, this->m_dismiss_line_data, this->m_center_label && this->m_data_title.length() < label.length() ? label.length() : this->m_data_title.length(), "jop1", this->m_data_title, this->get_color_by_name(this->m_color_data_title), this->get_color_by_name(this->m_color_data_table), label);
    std::cout << my_line;
    this->print_heder_table(array1,
        this->get_total_address(this->m_heddin_data_address),
        this->get_total_address(this->m_heddin_data_result),
        this->m_dismiss_word_data,
        this->get_color_by_name(this->m_color_address_data),
        this->get_color_by_name(this->m_color_total_data),
        this->m_type_table_operator != "on" ? 0 : this->get_color_by_name(this->m_color_operator_data),
        this->get_color_by_name(this->m_color_value_data),
        this->get_color_by_name(this->m_color_data_table));

    this->print_body_test(true, my_line, array1, vec,
        this->get_total_address(this->m_heddin_data_result),
        this->m_dismiss_word_data);
}

void Tables::show_result_with_operator(std::vector<Input> vec, std::string table_jop = "", std::string label = "") {
    if (this->m_heddin_table != "on" && table_jop == "")
        return;
    std::vector<std::string> array1;
    std::vector<std::vector<Input>> temp;
    int sizeOfHed = 0;
    int temp_title_table;
    if (table_jop == "jop1") 
        temp_title_table = this->m_center_label && this->m_result_title.length() < label.length() ? label.length() : this->m_result_title.length();
    else
        temp_title_table = this->m_result_table_suggestion.length();
    temp = this->init_result_auto_compleat(vec, table_jop, &sizeOfHed, &array1);
    if (temp.empty())
        return;
    this->set_total_address(table_jop != "" ? this->m_result_space : this->m_sugges_space,
        this->get_total_address(this->m_type_table_operator),
        this->get_total_address(table_jop != "" ? this->m_heddin_result : this->m_heddin_sugges_result),
        this->get_total_address(table_jop != "" ? this->m_heddin_result_address : this->m_heddin_sugges_address),
        &array1, table_jop != "" ? this->m_result_fill : this->m_sugges_fill, &temp, sizeOfHed);

    std::string my_line = table_jop != "" ? this->print_title(table_jop != "" ? this->m_line_result : this->m_line_sugges, &array1,
        table_jop != "" ? this->m_dismiss_line_result : this->m_dismiss_line_sugges,
        this->m_center_label && this->m_result_title.length() < label.length() ? label.length() : this->m_result_title.length(),
        table_jop, table_jop != "" ? this->m_result_title : this->m_result_table_suggestion,
        this->get_color_by_name(table_jop != "" ? this->m_color_result_title : this->m_color_sugges_title),
        this->get_color_by_name(table_jop != "" ? this->m_color_result_table : this->m_color_sugges_table),
        label) : this->print_title(table_jop != "" ? this->m_line_result : this->m_line_sugges, &array1,
            table_jop != "" ? this->m_dismiss_line_result : this->m_dismiss_line_sugges,
            this->m_result_table_suggestion.length(),
            table_jop, table_jop != "" ? this->m_result_title : this->m_result_table_suggestion,
            this->get_color_by_name(table_jop != "" ? this->m_color_result_title : this->m_color_sugges_title),
            this->get_color_by_name(table_jop != "" ? this->m_color_result_table : this->m_color_sugges_table),
            label);

    std::cout << my_line;
    this->print_heder_table(array1,
        this->get_total_address(table_jop != "" ? this->m_heddin_result_address: this->m_heddin_sugges_address),
        this->get_total_address(table_jop != "" ? this->m_heddin_result : this->m_heddin_sugges_result),
        table_jop != "" ? this->m_dismiss_word_result : this->m_dismiss_word_sugges,
        this->get_color_by_name(table_jop != "" ? this->m_color_address_result : this->m_color_address_sugges),
        this->get_color_by_name(table_jop != "" ? this->m_color_total_result : this->m_color_total_sugges),
        this->get_color_by_name(table_jop != "" ? this->m_color_operator_result : m_color_operator_sugges),
        this->get_color_by_name(table_jop != "" ? this->m_color_value_result : this->m_color_value_sugges),
        this->get_color_by_name(table_jop != "" ? this->m_color_result_table : this->m_color_sugges_table));

    this->print_body(my_line, temp, this->get_total_address(table_jop != "" ? this->m_heddin_result : this->m_heddin_sugges_result),
        table_jop != "" ? this->m_dismiss_word_result : this->m_dismiss_word_sugges,
        array1);
}

void Tables::display_table_menu(std::vector<std::vector<std::string>> vec, std::string word, std::string label, std::string title_menu) {
    std::vector<std::string> array1;
    for (int i = 0; i < vec.size(); i++) {
        word = vec[i][1] == word ? std::to_string(i) : word;
        for (int y = 0; y < this->m_menu_space; y++) {
            if(i <= 0)
                array1 = this->m_heddin_menu_address == "on" ? std::vector<std::string>{ " " + (y == 0 ? this->m_app : array1[0]) + " ", " " + (y == 0 ? this->m_app_address : array1[1]) + " "} : std::vector<std::string>{" " + (y == 0 ? this->m_app : array1[0]) + " "};
            vec[i] = { " " + vec[i][0] + " ", " " + (y == 0 ? std::to_string(i + 1) :vec[i][1]) + " ", (y != 0 ? vec[i][2] :vec[i][1])};
        }
        for (int z = 0; z < array1.size(); z++) {
            std::string value = vec.at(i).at(z);
            if (value.length() > array1[z].length()) {
                int myLen = value.length() - array1[z].length();
                for (int ii = 0; ii < myLen; ii++)
                    array1[z] += " ";
            }
        }
    }

    std::string my_line = this->print_title(this->m_line_menu,
        &array1,
        this->m_dismiss_line_menu,
        this->m_center_label && title_menu.length() < label.length() ? label.length() : title_menu.length(),
        "jop1",
        title_menu,
        this->get_color_by_name(this->m_color_menu_title),
        this->get_color_by_name(this->m_color_menu_table),
        label);
    std::cout << my_line;

    for (int i = 0; i < array1.size(); i++) {
        std::cout << this->m_dismiss_word_menu;
        if (i + 1 == array1.size() || i + 2 == array1.size())
            SetConsoleTextAttribute(hConsole, i + 1 != array1.size() ? this->get_color_by_name(this->m_color_app_menu) : this->get_color_by_name(this->m_color_address_menu));
        else
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_menu));
        
        std::cout << array1[i];
        SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
        if (i + 1 == array1.size())
            std::cout << this->m_dismiss_word_menu << std::endl;
    } 
    std::cout << my_line;
    for (int y = 0; y < vec.size(); y++) {
        if (word == std::to_string(y)) {// using if statment in color
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_select));
            std::cout << m_dismiss_word_menu;
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
        }
        else
            std::cout << m_dismiss_word_menu;
        for (int i = 0; i < array1.size(); i++) {
            std::string value = vec.at(y).at(i);
            if (value.length() < array1[i].length()) {
                int myLen = array1[i].length() - value.length();
                for (int i = 0; i < myLen; i++)
                    value += " ";
            } 
            if (word == std::to_string(y)) {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_select));
                std::cout << value << m_dismiss_word_menu;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
            }
            else if (vec[y][2] == "menu_exit") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_exit_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else if (vec[y][2] == "menu_search") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_search));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else if (vec[y][2] == "menu_add") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_add_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else if (vec[y][2] == "menu_delete") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_delete_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else if (vec[y][2] == "menu_update") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_edit_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else if (vec[y][2] == "menu_option") {
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_confirm_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;

            }
            else {//main
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_app_main_menu));
                std::cout << value;
                SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
                std::cout << m_dismiss_word_menu;
            }
        }
        if (word == std::to_string(y + 1) || word == std::to_string(y)) {
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_select));
            std::cout << std::endl << my_line;
            SetConsoleTextAttribute(hConsole, this->get_color_by_name(this->m_color_menu_table));
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










