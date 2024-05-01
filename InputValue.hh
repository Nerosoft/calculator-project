class InputValue : public Tables{
public:
    HANDLE hConsole;
    int m_id = 0;
    std::string test = "";
    std::string m_index = "";
    std::vector<Input>vec;
    InputValid m_input_valid;
    InputValue(){}
    //select
    InputValue(std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        if (this->myResult.size() != 0) {
            std::string label = this->m_print_message_user101;
            this->show_result_with_operator(nullptr, "jop1", label);
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
        this->m_input_valid = InputValid::input_mark_update_add;
        this->m_index = pos;
        std::string label = this->m_print_message_user102;

        if (value == "" && operator1 == "" && vec.empty() && test == "")
            this->display_table_confirm2(label);
        else {
          this->m_var1 = value;
          this->m_operator = operator1;
          this->vec = vec;
          this->test = test;
          if (operator1 == "=")
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
        this->m_input_valid = key != this->m_input_key102 ? InputValid::addition : InputValid::input_mark_search;
        this->m_index = key != this->m_input_key102 ? std::to_string(this->myResult.size() + 1) : this->m_interrogative;
        //this->m_id = id != 0 ? id : 0;
        if (this->myResult.size() != 0 && state) {
            std::string label = key != this->m_input_key102 ? this->m_print_number101 : this->m_print_number102;
            this->show_result_with_operator(nullptr, "jop1", label);
        }
        if (search != nullptr)
            *search = "";
    }  
    InputValue(std::string key, std::string value, std::string m_operator, std::string test, std::vector<Input>vec, int space, std::string *item, int id = 0) { //space for clear
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->m_input_valid = key != this->m_input_key102 ? InputValid::addition : InputValid::input_mark_search;
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
        std::string label = this->m_print_message_user103;
        this->tableResult77(this->vec, pos, label);
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
        this->m_input_valid = InputValid::input_mark_update_add;
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
        this->m_input_valid = InputValid::input_mark_update_add;
        if (item != nullptr && option != nullptr) {
            *option = this->m_input_key103;
            *item = pos;
        }
    }
    //end edit
   
    std::string getResult();
    std::string getResult(std::vector <Input>* vec);


    bool isValidInt();

    std::string searchItem(int id);
    std::vector<Input> search_by_id(int id);
    std::string check_vec(std::vector<Input> vec);
    std::string add_search_ubdate(std::string value);

    void set_value();
    bool valid_number();
    void print_statement(std::string word, int color);
    void print_statement(std::string word, int color, std::string* input_value);
    void print_statement(std::string word, int color, int* input_value);
private:
    void show_result_table(std::string label);
};

void InputValue::display_table_confirm(std::string label) {
    
    if (this->vec.empty() && test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->m_interrogative));
        this->tableResult77(v1, this->m_index, label);
    }

    else if (this->vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = this->vec;
        v1[0].m_result = this->m_value_result;
        this->tableResult77(v1, this->m_index, label);
    }
    else if (this->vec.size() >= 1) {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", ""));
        v1[0].m_result = this->getResult(&v1);
        this->tableResult77(v1, this->m_index, label);
    }
}

void InputValue::display_table_confirm2(std::string label) {
    int index = stoi(this->m_index);
    this->searchItem(index);
    std::vector<Input>v1 = this->vec;
    v1[0].m_result = this->getResult(&v1);
    this->tableResult77(v1, this->m_index, label);
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
    while (true)
    {
        if (this->m_var1 == this->get_m_input_menu(this->m_input_valid) || this->m_operator == this->get_m_input_menu(this->m_input_valid))
            return false;
        else if (this->m_var1 == this->get_m_input_help(this->m_input_valid) || this->m_operator == this->get_m_input_help(this->m_input_valid)) {
            std::string label = this->get_m_print_help(this->m_input_valid);
            int color_label = this->get_color_by_name(this->m_color_help);
            this->print_statement(label, color_label);
            label = test != "" ? this->get_m_print_operator(this->m_input_valid) : this->get_m_print_number(this->m_input_valid);
            color_label = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
        else if (this->m_var1 == this->get_m_input_result_table(this->m_input_valid) || this->m_operator == this->get_m_input_result_table(this->m_input_valid)) {
            std::string label = test != "" ? this->get_m_print_operator(this->m_input_valid) : this->get_m_print_number(this->m_input_valid);
            this->show_result_table(label);
            label = test != "" ? this->get_m_print_operator(this->m_input_valid) : this->get_m_print_number(this->m_input_valid);
            int color_label = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
        else if (this->m_var1 == this->get_m_input_clear(this->m_input_valid) || this->m_operator == this->get_m_input_clear(this->m_input_valid)) {
            vec.clear();
            std::string label = this->get_m_print_clear(this->m_input_valid);
            int color_label = this->get_color_by_name(this->m_color_clear);
            this->print_statement(label, color_label);
            this->m_operator = "";// for display table in confirm section when call constractor confirm and send operator
            label = this->get_m_print_number(this->m_input_valid);
            color_label = this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, &this->m_var1);
            test = "";
        }
        else if (this->m_var1[0] == '=' && this->m_var1.size() >= 2 || this->m_operator[0] == '=' && this->m_operator.size() >= 2) {
            this->set_value();
            for (int i = 0; i < (test != "" ? this->m_operator.size() : this->m_var1.size()); i++) {
                if (this->m_var1.length() >= MAX_SIZE_STRING || this->m_operator.length() >= MAX_SIZE_STRING
                    || this->m_var1[0] == '0' || this->m_operator[0] == '0'
                    || !isdigit(test != "" ? this->m_operator.at(i) : this->m_var1.at(i))
                    || stoi(test != "" ? this->m_operator: this->m_var1) > this->myResult.size() 
                    || stoi(test != "" ? this->m_operator: this->m_var1) < 1) {
                    std::string label = test != "+" ? this->get_m_print_error_number(this->m_input_valid) : this->get_m_print_error_operator(this->m_input_valid);
                    int color_label = test != "+" ? this->get_color_by_name(this->m_color_error_number) : this->get_color_by_name(this->m_color_error_operator);
                    this->print_statement(label, color_label);
                   
                    label = test != "+" ? this->get_m_print_number(this->m_input_valid) : this->get_m_print_operator(this->m_input_valid);
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
        else if (this->m_operator == "=" && vec.size() >= 1 && m_id != 0 || this->m_operator == "=" && vec.size() >= 1 && this->m_input_valid != InputValue::InputValid::input_mark_search) {
            vec.push_back(Input(this->m_var1, "", this->m_result));
            return false;
        }
        else if (this->m_operator == "+" && test != "" || this->m_operator == "-" && test != "" || this->m_operator == "*" && test != "" || this->m_operator == "/" && test != "" || this->valid_number() && test != "+")
            return false;
        else {
            std::string label = test != "" ? this->get_m_print_error_operator(this->m_input_valid): this->get_m_print_error_number(this->m_input_valid);
            int color_label = test != "" ? this->get_color_by_name(this->m_color_error_operator): this->get_color_by_name(this->m_color_error_number);
            this->print_statement(label, color_label);
            label = test != "" ? this->get_m_print_operator(this->m_input_valid): this->get_m_print_number(this->m_input_valid);
            color_label = test != "" ? this->get_color_by_name(this->m_color_operator): this->get_color_by_name(this->m_color_number);
            this->print_statement(label, color_label, test != "" ? &this->m_operator : &this->m_var1);
        }
    }
}

std::string InputValue::searchItem(int id = -1) {
    int index = id == -1 ? this->myResult.size() - stoi(this->m_var1) : this->myResult.size() - id;
    this->vec = this->myResult.at(index);
    this->vec[0].m_result = this->getResult();
    return std::to_string(id);
}

std::vector<Input> InputValue::search_by_id(int id) {
    int index =  this->myResult.size() - id;
    std::vector<Input> vec = this->myResult.at(index);
    vec[0].m_result = this->getResult(&vec);
    return vec;
}

std::string InputValue::check_vec(std::vector<Input> vec) {
    this->m_id = 0;
    std::string var1 = "", var2 = "";
    for (int z = 0; z < vec.size(); z++) {
        var1 += vec.at(z).m_var1;
        var1 += vec.at(z).m_operator;
    }
    for (int i = 0; i < this->myResult.size(); i++) {
        std::vector<Input> m_vec = this->myResult.at(i);
        var2 = "";
        for (int y = 0; y < m_vec.size(); y++) {
            var2 += m_vec.at(y).m_var1;
            var2 += m_vec.at(y).m_operator;
        }
        if (var1 == var2) {
            this->m_id = this->myResult.size() - i;
            break;
        }            
    }
    return  this->m_id != 0 ? std::to_string(this->m_id) : this->m_interrogative;
}



std::string InputValue::add_search_ubdate(std::string value) {
    if (value == this->get_m_input_menu(this->m_input_valid))
        return this->m_input_valid != InputValid::input_mark_search ? "" : std::to_string(this->m_id);
    else if (this->vec.empty() && this->test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->m_value_result));
        if (this->myResult.size() != 0)
            this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->get_m_print_number(this->m_input_valid) : this->get_m_print_operator(this->m_input_valid);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->m_interrogative, label);
    }
    else if (vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = vec;
        v1[0].m_result = this->m_value_result;
        if (this->myResult.size() != 0)
            this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->get_m_print_number(this->m_input_valid) : this->get_m_print_operator(this->m_input_valid);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->m_interrogative, label);
    }
    else if (vec.size() >= 1) {
        std::vector<Input>v1 = vec;
        v1.push_back(Input(this->m_var1, "", ""));
        v1[0].m_result = this->getResult(&v1);
        if (this->myResult.size() != 0)
         this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->get_m_print_number(this->m_input_valid) : this->get_m_print_operator(this->m_input_valid);
        std::string id = this->m_id != 0 ? std::to_string(this->m_id) : check_vec(v1);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : id, label);
    }
    do {
        std::string label1 = test != "" ? this->get_m_print_operator(m_input_valid) : this->get_m_print_number(this->m_input_valid);
        int color_label1 = test != "" ? this->get_color_by_name(this->m_color_operator) : this->get_color_by_name(this->m_color_number);
        this->print_statement(label1, color_label1, test != "" ? &this->m_operator : &this->m_var1); 
        if (this->isValidInt()) {
            this->m_var1 = test != "" ? this->m_operator : this->m_var1;
            this->searchItem();
            std::vector<Input> myInput = this->vec;
            vec.swap(myInput);
            if (this->myResult.size() != 0)
                this->show_result_with_operator(&vec);
            std::string label = this->get_m_print_operator(this->m_input_valid);
            this->tableResult77(vec, this->m_input_valid != InputValid::input_mark_search ? this->m_index : std::to_string(this->m_id), label);
            this->m_var1 = vec.at(vec.size() - 1).m_var1;
            vec.pop_back();
            test = "+";
            continue;
        }
        else if (this->m_var1 == this->get_m_input_menu(this->m_input_valid) ||
            this->m_operator == this->get_m_input_menu(this->m_input_valid)) {
            this->m_var1 = test != "+" ? "" : this->m_var1;// for display table in confirm section when call constractor confirm and send operator
            return this->get_m_input_menu(this->m_input_valid);
        }
        else if (this->m_operator == "=") {
            this->vec[0].m_result = this->getResult();
            return this->m_input_valid != InputValid::input_mark_search ? "" : std::to_string(this->m_id);
        }
        else if(test == "") {
            std::vector<Input>v1 = vec;
            v1.push_back(Input(this->m_var1, "", ""));
            show_result_with_operator(&v1);
            v1.at(0).m_result = this->getResult(&v1);
            std::string label = this->get_m_print_operator(this->m_input_valid);
            this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : check_vec(v1), label);
        }
        else {
            vec.push_back(Input(this->m_var1, this->m_operator, this->m_result));
            this->show_result_with_operator(&vec);
            std::vector<Input>myVector = vec;
            myVector.at(0).m_result = this->m_value_result;
            std::string label = this->get_m_print_number(this->m_input_valid);
            this->tableResult77(myVector, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->m_interrogative, label);
        }
        test = test != "" ? "" : "+";
    } while (true);
}

void InputValue::print_statement(std::string word, int color) {
    std::string temp = "";
    for (int i = 0; i < this->my_lable_space; i++)
        temp += " ";
    temp = this->m_star ? temp : temp + "*";
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
    if (this->myResult.size() != 0)
        this->show_result_with_operator(nullptr, "jop1", label);
}
