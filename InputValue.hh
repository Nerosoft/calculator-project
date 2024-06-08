class InputValue : public Input, public Tables{
public:
    HANDLE hConsole;
    int m_id = 0;
    std::string test = "";
    std::string m_index = "";
    std::vector<Input>vec;
    MenuEdit m_input_valid;
    InputValue(){}
    //select
    InputValue(std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        if (this->myResult.size() != 0) {
            std::string label = this->m_print_message_user101;
            std::vector<Input> empty_vec;
            this->show_result_with_operator(empty_vec, "jop1", label);
        } 
        if (item != nullptr)
            *item = "";
    }
    //end select

    void display_table_confirm(std::string label);
    void display_table_confirm2(std::string label);
    //start confirm
    InputValue(std::string* option, std::string pos, std::string*item) {// search and first screen and update -- item only for search
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->m_index = pos;
        std::string label = this->m_print_message_user102;
        this->display_table_confirm2(label);
        *option = "";
        if (item != nullptr)
            *item = pos;
    }
    InputValue(std::string *option, std::string pos, std::string value, std::string operator1, std::vector<Input>vec, std::string test, std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->m_input_valid = MenuEdit::input_mark_update_add;
        this->m_index = pos;
        std::string label = this->m_print_message_user102;

        if (value == "" && operator1 == "" && vec.empty() && test == "")
            this->display_table_confirm2(label);
        else {
          this->m_var1 = value;
          this->m_operator = operator1;
          this->vec = vec;
          this->test = test;
          if (operator1 == this->m_input_result103)
              this->vec.pop_back();
          this->display_table_confirm(label);
        }
        *option = "";
        if (item != nullptr)
            *item = pos;
    }
    //end confirm

    //start add and search
    InputValue(std::string key, bool state, std::string* search) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->m_input_valid = key != this->m_input_key102 ? MenuEdit::addition : MenuEdit::input_mark_search;
        this->m_index = key != this->m_input_key102 ? std::to_string(this->myResult.size() + 1) : this->m_interrogative;
        //this->m_id = id != 0 ? id : 0;
        if (this->myResult.size() != 0 && state) {
            std::string label = key != this->m_input_key102 ? this->m_print_number101 : this->m_print_number102;
            std::vector<Input> empty_vec;
            this->show_result_with_operator(empty_vec, "jop1", label);
        }
        if (search != nullptr)
            *search = "";
    }  
    InputValue(std::string key, std::string value, std::string m_operator, std::string test, std::vector<Input>vec, int space, std::string *item, int id = 0) { //space for clear
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->m_input_valid = key != this->m_input_key102 ? MenuEdit::addition : MenuEdit::input_mark_search;
        this->m_index = std::to_string(this->myResult.size() + 1);
        this->m_id = id != 0 ? id : 0;//best
        this->my_lable_space = space;
        this->test = test;
        this->vec = vec;
        this->m_var1 = value;
        this->m_operator = m_operator;
        if (item != nullptr)
            *item = key;
    }
    //end add
    
     
    //start delete
    InputValue(std::string pos, std::string* option, std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->searchItem(stoi(pos));
        this->m_index = pos;
        std::string label = this->m_print_statement_confirm104;
        this->vec[0].m_index = pos;
        this->tableResult77(this->vec, label);
        if (option != nullptr && item != nullptr) {
            *item = pos;
            *option = this->m_input_key104;
        }
    }
    //end delete
 
    //start edit 
    InputValue(std::string* option, std::string* item, std::string pos) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->searchItem(stoi(pos));
        this->m_var1 = this->vec[this->vec.size() - 1].m_var1;
        this->test = "+";
        this->vec.pop_back();
        this->m_index = pos;
        this->m_input_valid = MenuEdit::input_mark_update_add;
        if (option != nullptr && item != nullptr) {
            *item = pos;
            *option = this->m_input_key103;
        }
    }
    InputValue(std::string pos, int space, std::string test, std::string value, std::string m_operator, std::vector<Input>vec, std::string* item, std::string* option) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->my_lable_space = space;
        this->vec = vec;
        this->m_var1 = value;
        this->m_operator = m_operator;
        this->test = test;
        this->m_index = pos;
        this->m_input_valid = MenuEdit::input_mark_update_add;
        if (item != nullptr && option != nullptr) {
            *option = this->m_input_key103;
            *item = pos;
        }
    }
    //end edit
   
   



    std::string add_search_ubdate(std::string value);
    void print_statement(std::string word, int color);
    void print_statement(std::string word, int color, std::string* input_value);
    void print_statement(std::string word, int color, int* input_value);
    std::string get_m_print_help(MenuEdit menu_edit);
private:
    void show_result_table(std::string label);
    bool get_valid_menu(std::string value);
    bool get_valid_help(std::string value);
    bool get_valid_result_table(std::string value);
    bool get_valid_clear(std::string value);
    bool get_input_result();
    bool get_input_search(char value);
    std::string get_m_input_menu();
    bool isValidInt();
    std::string searchItem(int id);
    std::string check_vec(std::vector<Input> vec);
    std::string getResult();
    std::string getResult(std::vector <Input>* vec);
    void set_value();
    bool valid_number();
    std::string get_m_print_operator();
    std::string get_m_print_number();
    std::string get_m_print_clear();
    std::string get_m_print_error_number();
    std::string get_m_print_error_operator();
    std::string get_m_print_successfuly_select_item(MenuEdit input_value);
};

std::string InputValue::get_m_print_successfuly_select_item(MenuEdit input_value) {
    if (input_value == MenuEdit::addition)
        return this->m_print_successfuly_select_item101;
    else if (input_value == MenuEdit::input_mark_search)
        return this->m_print_successfuly_select_item102;
    else
        return this->m_print_successfuly_select_item103;
}

std::string InputValue::get_m_print_error_number() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_print_error_number101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_print_error_number102;
    // InputValid::input_mark_update_add
    else
        return this->m_print_error_number103;
}

std::string InputValue::get_m_print_error_operator() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_print_error_operator101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_print_error_operator102;
    //InputValid::input_mark_update_add:
    else
        return this->m_print_error_operator103;
}

std::string InputValue::get_m_print_clear() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_print_clear101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_print_clear102;
    //InputValid::input_mark_update_add:
    else
        return this->m_print_clear103;
}

std::string InputValue::get_m_print_number() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_print_number101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_print_number102;
    //input_value == InputValid::input_mark_update_add
    else
        return this->m_print_number103;
}

std::string InputValue::get_m_print_operator() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_print_operator101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_print_operator102;
    //input_value == InputValid::input_mark_update_add
    else
        return this->m_print_operator103;
}

std::string InputValue::get_m_print_help(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::first_opration)
        return this->m_print_help104;
    else if (menu_edit == MenuEdit::chose_operation)
        return this->m_print_help105;
    else if (menu_edit == MenuEdit::message102 || menu_edit == MenuEdit::addition)
        return this->m_print_help101;
    else if (menu_edit == MenuEdit::message101 || menu_edit == MenuEdit::input_mark_search)
        return this->m_print_help102;
    else if (menu_edit == MenuEdit::message103 || menu_edit == MenuEdit::input_mark_update_add)
        return this->m_print_help103;
    //MenuEdit::message104:
    else
        return this->m_print_help106;
}

bool InputValue::get_valid_menu(std::string value) {
    return value == this->m_input_menu101 && this->m_input_valid == MenuEdit::addition || value == this->m_input_menu102 && this->m_input_valid == MenuEdit::input_mark_search || value == this->m_input_menu103 && this->m_input_valid == MenuEdit::input_mark_update_add;
}

bool InputValue::get_valid_help(std::string value) {
    return value == this->m_input_help101 && this->m_input_valid == MenuEdit::addition || value == this->m_input_help102 && this->m_input_valid == MenuEdit::input_mark_search || value == this->m_input_help103 && this->m_input_valid == MenuEdit::input_mark_update_add;
}

bool InputValue::get_valid_result_table(std::string value) {
    return value == this->m_input_result_table101 && this->m_input_valid == MenuEdit::addition || value == this->m_input_result_table102 && this->m_input_valid == MenuEdit::input_mark_search || value == this->m_input_result_table103 && this->m_input_valid == MenuEdit::input_mark_update_add;
}

bool InputValue::get_valid_clear(std::string value) {
    return value == this->m_input_clear101 && this->m_input_valid == MenuEdit::addition || value == this->m_input_clear102 && this->m_input_valid == MenuEdit::input_mark_search || value == this->m_input_clear103 && this->m_input_valid == MenuEdit::input_mark_update_add;
}

bool InputValue::get_input_result() {
    return this->m_operator == this->m_input_result101 && this->m_input_valid == MenuEdit::addition || this->m_operator == this->m_input_result102 && this->m_input_valid == MenuEdit::input_mark_search || this->m_operator == this->m_input_result103 && this->m_input_valid == MenuEdit::input_mark_update_add;
}

bool InputValue::get_input_search(char value) {
    return value == this->m_input_search101[0] && this->m_input_valid == MenuEdit::addition || value == this->m_input_search102[0] && this->m_input_valid == MenuEdit::input_mark_search || value == this->m_input_search103[0] && this->m_input_valid == MenuEdit::input_mark_update_add;
}

std::string InputValue::get_m_input_menu() {
    if (this->m_input_valid == MenuEdit::addition)
        return this->m_input_menu101;
    else if (this->m_input_valid == MenuEdit::input_mark_search)
        return this->m_input_menu102;
    else //if(menu_edit == MenuEdit::input_mark_update_add)
        return this->m_input_menu103;
}

void InputValue::display_table_confirm(std::string label) {
    
    if (this->vec.empty() && test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->m_interrogative));
        v1[0].m_index = this->m_index;
        this->tableResult77(v1, label);
    }

    else if (this->vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = this->vec;
        v1[0].m_result = this->m_value_result;
        v1[0].m_index = this->m_index;
        this->tableResult77(v1, label);
    }
    else if (this->vec.size() >= 1) {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", ""));
        v1[0].m_result = this->getResult(&v1);
        v1[0].m_index = this->m_index;
        this->tableResult77(v1, label);
    }
}

void InputValue::display_table_confirm2(std::string label) {
    int index = stoi(this->m_index);
    this->searchItem(index);
    std::vector<Input>v1 = this->vec;
    v1[0].m_result = this->getResult(&v1);
    v1[0].m_index = this->m_index;
    this->tableResult77(v1, label);
}

std::string InputValue::getResult() {// my vec of class
    if (vec.size() == 1)
        return this->m_value_result;
    std::string value = vec.at(0).m_var1;
    for (int i = 0; i < vec.size(); i++)
        if (vec.at(i).m_operator == "+")
            value = std::to_string(stof(value) + stof(vec.at(i + 1).m_var1));
        else if (vec.at(i).m_operator == "-")
            value = std::to_string(stof(value) - stof(vec.at(i + 1).m_var1));
        else if (vec.at(i).m_operator == "*")
            value = std::to_string(stof(value) * stof(vec.at(i + 1).m_var1));
        else if (vec.at(i).m_operator == "/")
            value = std::to_string(stof(value) / stof(vec.at(i + 1).m_var1));
    return value;
}

std::string InputValue::getResult(std::vector <Input>* vec) {// any vec
    if (vec->size() == 1)
        return this->m_value_result;
    std::string value = vec->at(0).m_var1;
    for (int i = 0; i < vec->size(); i++)
        if (vec->at(i).m_operator == "+")
            value = std::to_string(stof(value) + stof(vec->at(i + 1).m_var1));
        else if (vec->at(i).m_operator == "-")
            value = std::to_string(stof(value) - stof(vec->at(i + 1).m_var1));
        else if (vec->at(i).m_operator == "*")
            value = std::to_string(stof(value) * stof(vec->at(i + 1).m_var1));
        else if (vec->at(i).m_operator == "/")
            value = std::to_string(stof(value) / stof(vec->at(i + 1).m_var1));
    return value;
}
void InputValue::set_value() {
    if (test != "")
        this->m_operator.erase(this->m_operator.begin());
    else
        this->m_var1.erase(this->m_var1.begin());
}
bool InputValue::valid_number() {
    try {
        for (int i = this->m_var1.at(0) == '-' && this->m_var1.size() > 1 ? 1 : 0; i < this->m_var1.size(); i++) {
            if (this->m_var1.find("-0") == 0
                || this->m_operator == "/" && this->m_var1 == "0"
                || !isdigit(this->m_var1.at(i))
                || this->m_var1.at(0) == '0' && this->m_var1.length() > 1
                || this->m_var1.length() > MAX_SIZE_STRING)
                return false;
            else if (i + 1 == this->m_var1.size())
                return true;
        }
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
        return false;
    }

}
bool InputValue::isValidInt() {
    
    do{
        if (this->get_valid_menu(this->m_var1) || this->get_valid_menu(this->m_operator))
            return false;
        else if (this->get_valid_help(this->m_var1) || this->get_valid_help(this->m_operator)) {
            std::string label = this->get_m_print_help(this->m_input_valid);
            int color_label = this->get_color_by_name(this->m_color_help);
            this->print_statement(label, color_label);
            label = test != "" ? this->get_m_print_operator() : this->get_m_print_number();
            color_label = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
        else if (this->get_valid_result_table(this->m_var1) || this->get_valid_result_table(this->m_operator)) {
            std::string label = test != "" ? this->get_m_print_operator() : this->get_m_print_number();
            this->show_result_table(label);
            label = test != "" ? this->get_m_print_operator() : this->get_m_print_number();
            int color_label = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
        else if (this->get_valid_clear(this->m_var1) || this->get_valid_clear(this->m_operator)) {
            vec.clear();
            std::string label = this->get_m_print_clear();
            int color_label = this->get_color_by_name(this->m_color_clear);
            this->print_statement(label, color_label);
            this->m_operator = "";// for display table in confirm section when call constractor confirm and send operator
            label = this->get_m_print_number();
            color_label = this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, &this->m_var1);
            test = test != "" ? "" : test;
        }
        else if (this->get_input_search(this->m_var1[0]) && this->m_var1.size() >= 2 || this->get_input_search(this->m_operator[0]) && this->m_operator.size() >= 2) {
            this->set_value();
            for (int i = 0; i < (test != "" ? this->m_operator.size() : this->m_var1.size()); i++) {
                if (this->m_var1.length() >= MAX_SIZE_STRING || this->m_operator.length() >= MAX_SIZE_STRING
                    || this->m_var1[0] == '0' || this->m_operator[0] == '0'
                    || !isdigit(test != "" ? this->m_operator.at(i) : this->m_var1.at(i))
                    || stoi(test != "" ? this->m_operator: this->m_var1) > this->myResult.size() 
                    || stoi(test != "" ? this->m_operator: this->m_var1) < 1) {
                    std::string label = test != "+" ? this->get_m_print_error_number() : this->get_m_print_error_operator();
                    int color_label = test != "+" ? this->get_color_by_name(this->m_color_error_number) : this->get_color_by_name(this->m_color_error_operator);
                    this->print_statement(label, color_label);
                   
                    label = test != "+" ? this->get_m_print_number() : this->get_m_print_operator();
                    color_label = test != "+" ? this->get_color_by_name(this->m_color_number) : this->get_color_by_name(this->m_color_operator);
                    this->print_statement(label, color_label, test != "+" ? &this->m_var1 : &this->m_operator);
                    break;
                }
                else if (i + 1 == (test != "" ? this->m_operator.size() : this->m_var1.size())) {
                    m_id = stoi(test != "" ? this->m_operator : this->m_var1);
                    return true;
                }
            }
        }       
        else if (this->get_input_result() && vec.size() >= 1 && m_id != 0 || this->get_input_result() && vec.size() >= 1 && this->m_input_valid != MenuEdit::input_mark_search) {
            vec.push_back(Input(this->m_var1, "", this->m_result));
            return false;
        }
        else if (this->m_operator == "+" && test != "" || this->m_operator == "-" && test != "" || this->m_operator == "*" && test != "" || this->m_operator == "/" && test != "" || this->valid_number() && test != "+")
            return false;
        else {
            std::string label = test != "" ? this->get_m_print_error_operator(): this->get_m_print_error_number();
            int color_label = test != "" ? this->get_color_by_name(this->m_color_error_operator): this->get_color_by_name(this->m_color_error_number);
            this->print_statement(label, color_label);
            label = test != "" ? this->get_m_print_operator(): this->get_m_print_number();
            color_label = test != "" ? this->get_color_by_name(this->m_color_operator): this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
    } while (true);
}

std::string InputValue::searchItem(int id = -1) {
    int index = id == -1 ? this->myResult.size() - stoi(this->m_var1) : this->myResult.size() - id;
    this->vec = this->myResult.at(index);
    this->vec[0].m_result = this->getResult();
    return std::to_string(id);
}

std::string InputValue::check_vec(std::vector<Input> vec) {
    this->m_id = 0;
    std::string var1 = this->get_text_search(vec), var2 = "";
    for (int i = 0; i < this->myResult.size(); i++) {
        std::vector<Input> m_vec = this->myResult.at(i);
        var2 = "";
        for (int y = 0; y < m_vec.size(); y++)
            var2 += m_vec.at(y).m_var1 + m_vec.at(y).m_operator;
        if (var1 == var2) {
            this->m_id = this->myResult.size() - i;
            break;
        }            
    }
    return  this->m_id != 0 ? std::to_string(this->m_id) : this->m_interrogative;
}

std::string InputValue::add_search_ubdate(std::string value) {
    if (this->get_valid_menu(value))
        //return this->m_input_valid != MenuEdit::input_mark_search ? "" : std::to_string(this->m_id);
        return "";

    else if (this->vec.empty() && this->test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->m_value_result));
        if (this->myResult.size() != 0)
            this->show_result_with_operator(v1);
        std::string label = this->test != "+" ? this->get_m_print_number() : this->get_m_print_operator();
        v1[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : this->m_interrogative;
        this->tableResult77(v1, label);
    }
    else if (vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = vec;
        v1[0].m_result = this->m_value_result;
        if (this->myResult.size() != 0)
            this->show_result_with_operator(v1);
        std::string label = this->test != "+" ? this->get_m_print_number() : this->get_m_print_operator();
        v1[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : this->m_interrogative;
        this->tableResult77(v1, label);
    }
    else if (vec.size() >= 1) {
        std::vector<Input>v1 = vec;
        v1.push_back(Input(this->m_var1, "", ""));
        v1[0].m_result = this->getResult(&v1);
        if (this->myResult.size() != 0)
         this->show_result_with_operator(v1);
        std::string label = this->test != "+" ? this->get_m_print_number() : this->get_m_print_operator();
        v1[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : this->m_id != 0 ? std::to_string(this->m_id) : check_vec(v1);
        this->tableResult77(v1, label);
    }
    do {
        std::string label1 = test != "" ? this->get_m_print_operator() : this->get_m_print_number();
        int color_label1 = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
        this->print_statement(label1, color_label1, test != "" ? &this->m_operator : &this->m_var1); 
        if (this->isValidInt()) {
            this->m_var1 = test != "" ? this->m_operator : this->m_var1;
            this->searchItem();
            std::vector<Input> myInput = this->vec;
            vec.swap(myInput);

            std::string label = this->get_m_print_successfuly_select_item(this->m_input_valid);
            int color_label =  this->get_color_by_name(this->m_color_successfully_statement_message_confirm);
            print_statement(label, color_label);

            if (this->myResult.size() != 0)
                this->show_result_with_operator(vec);
            label = this->get_m_print_operator();
            vec[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : std::to_string(this->m_id);
            this->tableResult77(vec, label);
            this->m_var1 = vec.at(vec.size() - 1).m_var1;
            vec.pop_back();
            //test = test != "" ? test : "+";
            test = "+";
            continue;
        }
        else if (this->get_valid_menu(this->m_var1) || this->get_valid_menu(this->m_operator)) {
            this->m_var1 = test != "+" ? "" : this->m_var1;// for display table in confirm section when call constractor confirm and send operator
            return this->get_m_input_menu();
        }
        else if (this->m_operator == this->m_input_result101 && this->m_input_valid == MenuEdit::addition || this->m_operator == this->m_input_result102 && this->m_input_valid == MenuEdit::input_mark_search || this->m_operator == this->m_input_result103 && this->m_input_valid == MenuEdit::input_mark_update_add ) {
            this->vec[0].m_result = this->getResult();
            //return this->m_input_valid != MenuEdit::input_mark_search ? "" : std::to_string(this->m_id);
            return "";
        }
        else if(test == "") {
            std::vector<Input>v1 = vec;
            v1.push_back(Input(this->m_var1, "", ""));
            show_result_with_operator(v1);
            v1.at(0).m_result = this->getResult(&v1);
            std::string label = this->get_m_print_operator();
            v1[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : check_vec(v1);
            this->tableResult77(v1, label);
        }
        else {
            vec.push_back(Input(this->m_var1, this->m_operator, this->m_result));
            this->show_result_with_operator(vec);
            std::vector<Input>myVector = vec;
            myVector.at(0).m_result = this->m_value_result;
            std::string label = this->get_m_print_number();
            myVector[0].m_index = this->m_input_valid != MenuEdit::input_mark_search ? this->m_index : this->m_interrogative;
            this->tableResult77(myVector, label);
        }
        test = test != "" ? "" : "+";
    } while (true);
}

void InputValue::print_statement(std::string word, int color) {
    std::string temp = "";
    for (int i = 0; i < this->my_lable_space; i++)
        temp += " ";
    SetConsoleTextAttribute(this->hConsole, color);
    std::cout << temp << word << std::endl;
    SetConsoleTextAttribute(this->hConsole, DEFAULT_COLOR);
}

void InputValue::print_statement(std::string word, int color, std::string* input_value) {
    std::string temp = "";
    for (int i = 0; i < this->my_lable_space; i++)
        temp += " ";
    temp = this->m_star ? temp : temp + "*";
    SetConsoleTextAttribute(this->hConsole, color);
    std::cout << temp << word;
    SetConsoleTextAttribute(this->hConsole, DEFAULT_COLOR);
    std::cin >> std::ws;
    getline(std::cin, *input_value);
}

void InputValue::print_statement(std::string word, int color, int* input_value) {// for int
    std::string temp = "";
    for (int i = 0; i < this->my_lable_space; i++)
        temp += " ";
    temp = this->m_star ? temp : temp + "*";
    SetConsoleTextAttribute(this->hConsole, color);
    std::cout << temp << word;
    SetConsoleTextAttribute(this->hConsole, DEFAULT_COLOR);
    std::cin >> std::ws;
    std::cin >> *input_value;
}

void InputValue::show_result_table(std::string label) {
    if (this->myResult.size() != 0) {
        std::vector<Input> empty_vec;
        this->show_result_with_operator(empty_vec, "jop1", label);
    }
}