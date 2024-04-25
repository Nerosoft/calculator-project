class InputValue : public Input, public Tables{
public:
    HANDLE hConsole;
    int m_id = 0;
    std::string test = "";
    std::string m_index = "";
    std::vector<Input>vec;
    InputValid m_input_valid;
    InputValue(){}
    //----------------------------------valid - select and menu select--------------------------------------------------------------------
    InputValue(std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        if (this->myResult.size() != 0) {
            std::string label = this->language.m_print_message_user101;
            this->show_result_with_operator(nullptr, "jop1", label);
        } 
        //*item = "" ;
        //*option = option != nullptr ? var : *option;
       
        if (item != nullptr)
            *item = "";
    }
    //----------------------------------end select----------------------------------------------------------------------------------------

    void display_table_confirm(std::string label);
    void display_table_confirm2(std::string label);
    //------------------------------------valid - confirm----------------------------------------------------
    InputValue(std::string* option, std::string pos, std::string*item) {// search and first screen and update -- item only for search
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        //this->m_input_valid = InputValid::input_mark_update_add;
        this->m_index = pos;
        std::string label = this->language.m_print_message_user102;
        this->display_table_confirm2(label);
        *option = "";
        if (item != nullptr)
            *item = pos;
    }
    InputValue(std::string *option, std::string pos, std::string value, std::string operator1, std::vector<Input>vec, std::string test, std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->m_input_valid = InputValid::input_mark_update_add;
        this->m_index = pos;
        std::string label = this->language.m_print_message_user102;

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
    //------------------------------------end confirm--------------------------------------------------------

    //----------------------------valid - add and menu add and-search-----------------------------------------------------------------------------------------
   
    InputValue(std::string key, bool state, std::string* search) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->m_input_valid = key != this->language.m_input_key102 ? InputValid::addition : InputValid::input_mark_search;
        this->m_index = key != this->language.m_input_key102 ? std::to_string(this->myResult.size() + 1) : this->language.m_interrogative;
        //this->m_id = id != 0 ? id : 0;
        if (this->myResult.size() != 0 && state) {
            std::string label = key != this->language.m_input_key102 ? this->language.m_print_number101 : this->language.m_print_number102;
            this->show_result_with_operator(nullptr, "jop1", label);
        }
        if (search != nullptr)
            *search = "";
    }  
    InputValue(std::string key, std::string value, std::string m_operator, std::string test, std::vector<Input>vec, int space, std::string *item, int id = 0) { //space for clear
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->m_input_valid = key != this->language.m_input_key102 ? InputValid::addition : InputValid::input_mark_search;
        //this->m_index = key != this->language.m_input_key102 ? std::to_string(this->myResult.size() + 1) : index;
        this->m_index = std::to_string(this->myResult.size() + 1);
        this->m_id = id != 0 ? id : 0;//best
        this->my_lable_space = space;
        this->test = test;
        this->vec = vec;
        this->m_var1 = value;
        this->m_operator = m_operator;
       // *item = key;
        if (item != nullptr)
            *item = key;
    }
    //-----------------------------end add--------------------------------------------------------------------------------------------------------
    
    
    //--------------------------------------------------------------------------------------------------------



    //InputValue(){
    //}
   
     
    //-----------------------------delete--------------------------------------------------------------------------
    InputValue(std::string pos, std::string* option, std::string* item) {
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->get_culc_Result();
        this->searchItem(stoi(pos));
        this->m_index = pos;
        std::string label = this->language.m_print_message_user103;
        this->tableResult77(this->vec, pos, label);
        if (option != nullptr && item != nullptr) {
            *item = pos;
            *option = this->language.m_input_key104;
        }
    }
    //----------------------------end-delete--------------------------------------------------------------------------
 
    // --------------------------------------for edit----------------------------------------------------------------------  
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
            *option = this->language.m_input_key103;
        }
        //*option = option != nullptr ? var : *option;
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
            *option = this->language.m_input_key103;
            *item = pos;
        }
    }
    //--------------------------------------end edit-----------------------------------------------------------------------
   
    std::string getResult();
    std::string getResult(std::vector <Input>* vec);


    bool isValidInt(InputValid section, std::string state, std::string* input_value);

    std::string searchItem(int id);
    std::vector<Input> search_by_id(int id);
    std::string check_vec(std::vector<Input> vec);
    std::string add_search_ubdate(std::string value);

    void print_statement(std::string word, int color);
    void print_statement(std::string word, int color, std::string* input_value);
    void print_statement(std::string word, int color, int* input_value);
private:
    void show_result_table(std::string label);
};

void InputValue::display_table_confirm(std::string label) {
    
    if (this->vec.empty() && test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->language.m_interrogative));
        this->tableResult77(v1, this->m_index, label);
    }

    else if (this->vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = this->vec;
        v1[0].m_result = this->language.m_value_result;
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
        return this->language.m_value_result;
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
        return this->language.m_value_result;
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

bool InputValue::isValidInt(InputValid section, std::string state, std::string* input_value) {
    while (true)
    {
        if (*input_value == this->language.get_m_input_menu(section)) {
            return false;
        }
        else if (*input_value == this->language.get_m_input_help(section)) {
            std::string label = this->language.get_m_print_help(section);
            int color_label = this->get_color_by_name(this->language.m_color_help);
            this->print_statement(label, color_label);
            label = state != "" ? this->language.get_m_print_operator(section) : this->language.get_m_print_number(section);
            color_label = state != "" ? this->get_color_by_name(this->language.m_color_operator) : this->get_color_by_name(this->language.m_color_number);
            this->print_statement(label, color_label, input_value);
        }
        else if (*input_value == this->language.get_m_input_result_table(section)) {
            std::string label = state != "" ? this->language.get_m_print_operator(section) : this->language.get_m_print_number(section);
            this->show_result_table(label);
            label = state != "" ? this->language.get_m_print_operator(section) : this->language.get_m_print_number(section);
            int color_label = state != "" ? this->get_color_by_name(this->language.m_color_operator) : this->get_color_by_name(this->language.m_color_number);
            this->print_statement(label, color_label, input_value);
        }
        else if (*input_value == this->language.get_m_input_clear(section)) {
            vec.clear();
            std::string label = this->language.get_m_print_clear(section);
            int color_label = this->get_color_by_name(this->language.m_color_clear);
            this->print_statement(label, color_label);
            if (state == "+") 
                return false;
            this->m_operator = "";// for display table in confirm section when call constractor confirm and send operator
            label = this->language.get_m_print_number(section);
            color_label = this->get_color_by_name(this->language.m_color_number);
            this->print_statement(label, color_label, input_value);
        }
        else if (input_value->at(0) == '=' && input_value->size() >= 2 ) {
            input_value->erase(input_value->begin());
            for (int i = 0; i < input_value->size(); i++) {
                if (input_value->length() >= MAX_SIZE_STRING || input_value->at(0) == '0' || !isdigit(input_value->at(i)) || stoi(*input_value) > this->myResult.size() || stoi(*input_value) < 1) {
                    std::string label = state != "+" ? this->language.get_m_print_error_number(section) : this->language.get_m_print_error_operator(section);
                    int color_label = state != "+" ? this->get_color_by_name(this->language.m_color_error_number) : this->get_color_by_name(this->language.m_color_error_operator);
                    this->print_statement(label, color_label);
                   
                    label = state != "+" ? this->language.get_m_print_number(section) : this->language.get_m_print_operator(section);
                    color_label = state != "+" ? this->get_color_by_name(this->language.m_color_number) : this->get_color_by_name(this->language.m_color_operator);
                    this->print_statement(label, color_label, input_value);
                    break;
                }
                else if (i + 1 == input_value->size()) {
                    m_id = stoi(*input_value);
                    return state != "+" ? true : false;
                }
            }
        }
        else if (state == "")
            try {
            for (int i = input_value->at(0) == '-' && input_value->size() > 1 ? 1 : 0; i < input_value->size(); i++) {
                if (input_value->find("-0") == 0
                    || this->m_operator == "/" && *input_value == "0"
                    || !isdigit(input_value->at(i))
                    || input_value->at(0) == '0' && input_value->length() > 1
                    || input_value->length() > MAX_SIZE_STRING) {
                    std::string label = this->language.get_m_print_error_number(section);
                    int color_label = this->get_color_by_name(this->language.m_color_error_number);
                    this->print_statement(label, color_label);
                    label = this->language.get_m_print_number(section);
                    color_label = this->get_color_by_name(this->language.m_color_number);
                    this->print_statement(label, color_label, input_value);
                    break;
                }
                else if (i + 1 == input_value->size()) {
                    return false;
                }
            }
        }
        catch (std::exception& e) {
            std::cout << "Standard exception: result" << e.what() << std::endl;

        }
        else if (*input_value == "=" && vec.size() >= 1 && m_id != 0 || *input_value == "=" && vec.size() >= 1 && section != InputValue::InputValid::input_mark_search) {
            vec.push_back(Input(this->m_var1, "", this->m_result));
            return false;
        }
        else if (*input_value == "+" || *input_value == "-" || *input_value == "*" || *input_value == "/")
            return true;
        else {
            std::string label = this->language.get_m_print_error_operator(section);
            int color_label = this->get_color_by_name(this->language.m_color_error_operator);
            this->print_statement(label, color_label);
            label = this->language.get_m_print_operator(section);
            color_label = this->get_color_by_name(this->language.m_color_operator);
            this->print_statement(label, color_label, input_value);
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
    return  this->m_id != 0 ? std::to_string(this->m_id) : this->language.m_interrogative;
}



std::string InputValue::add_search_ubdate(std::string value) {
    if (value == this->language.get_m_input_menu(this->m_input_valid))
        return this->m_input_valid != InputValid::input_mark_search ? "" : std::to_string(this->m_id);
    else if (this->vec.empty() && this->test != "") {
        std::vector<Input>v1 = this->vec;
        v1.push_back(Input(this->m_var1, "", this->language.m_value_result));
        if (this->myResult.size() != 0)
            this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->language.get_m_print_number(this->m_input_valid) : this->language.get_m_print_operator(this->m_input_valid);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->language.m_interrogative, label);
    }
    else if (vec.size() >= 1 && test == "") {
        std::vector<Input>v1 = vec;
        v1[0].m_result = this->language.m_value_result;
        if (this->myResult.size() != 0)
            this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->language.get_m_print_number(this->m_input_valid) : this->language.get_m_print_operator(this->m_input_valid);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->language.m_interrogative, label);
    }
    else if (vec.size() >= 1) {
        std::vector<Input>v1 = vec;
        v1.push_back(Input(this->m_var1, "", ""));
        v1[0].m_result = this->getResult(&v1);
        if (this->myResult.size() != 0)
         this->show_result_with_operator(&v1);
        std::string label = this->test != "+" ? this->language.get_m_print_number(this->m_input_valid) : this->language.get_m_print_operator(this->m_input_valid);
        std::string id = this->m_id != 0 ? std::to_string(this->m_id) : check_vec(v1);
        this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : id, label);
    }
    do {
        if (test == "") {
            std::string label = this->language.get_m_print_number(this->m_input_valid);
            int color_label = this->get_color_by_name(this->language.m_color_number);
            this->print_statement(label, color_label, &this->m_var1);
            if (this->isValidInt(this->m_input_valid, test, &this->m_var1)) {
                this->searchItem();
                std::vector<Input> myInput = this->vec;
                vec.swap(myInput);
                if (this->myResult.size() != 0)
                    this->show_result_with_operator(&vec);
                std::string label = this->language.get_m_print_operator(this->m_input_valid);
                this->tableResult77(vec, this->m_input_valid != InputValid::input_mark_search ? this->m_index : std::to_string(this->m_id), label);
                this->m_var1 = vec.at(vec.size() - 1).m_var1;
                vec.pop_back();
            }
            else if (this->m_var1 == this->language.get_m_input_menu(this->m_input_valid)) {
                this->m_var1 = "";
                test = "";
                return this->language.get_m_input_menu(this->m_input_valid);
            }
            else {
                std::vector<Input>v1 = vec;
                v1.push_back(Input(this->m_var1, "", ""));
                if (this->myResult.size() != 0)
                    show_result_with_operator(&v1);
                v1.at(0).m_result = this->getResult(&v1);
                std::string label = this->language.get_m_print_operator(this->m_input_valid);
                this->tableResult77(v1, this->m_input_valid != InputValid::input_mark_search ? this->m_index : check_vec(v1), label);
            }
        }

        std::string label = this->language.get_m_print_operator(m_input_valid);
        int color_label = this->get_color_by_name(this->language.m_color_operator);
        this->print_statement(label, color_label, &this->m_operator);
        bool state_validation = this->isValidInt(this->m_input_valid, test != "" ? test : "+", &this->m_operator);
        if (vec.empty() && state_validation) {
            vec.push_back(Input(this->m_var1, this->m_operator, this->m_result));
            if (this->myResult.size() != 0)
                this->show_result_with_operator(&vec);
            std::vector<Input>myVector = vec;
            myVector.at(myVector.size() - 1).m_operator = this->m_operator;
            myVector.at(0).m_result = this->language.m_value_result;
            std::string label = this->language.get_m_print_number(this->m_input_valid);
            this->tableResult77(myVector, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->language.m_interrogative, label);
        }
        else if (state_validation) {
            if(vec.at(vec.size() - 1).m_operator == "")
                vec.at(vec.size() - 1).m_operator = this->m_operator;
            else
                vec.push_back(Input(this->m_var1, this->m_operator, this->m_result));
            if (this->myResult.size() != 0)
                this->show_result_with_operator(&vec);
            std::vector<Input>myVector = vec;
            myVector.at(myVector.size() - 1).m_operator = this->m_operator;
            myVector.at(0).m_result = this->language.m_value_result;
            std::string label = this->language.get_m_print_number(this->m_input_valid);
            this->tableResult77(myVector, this->m_input_valid != InputValid::input_mark_search ? this->m_index : this->language.m_interrogative, label);
        }
        else if (this->m_operator == this->language.get_m_input_menu(this->m_input_valid)) {
            this->m_operator = "";
            test = "+";
            return this->language.get_m_input_menu(this->m_input_valid);
        }
        else if (this->m_operator == this->language.get_m_input_clear(this->m_input_valid))
            this->m_operator = "";
        else if (this->m_operator == "=") {
            test = "+";
            this->vec[0].m_result = this->getResult();
            return this->m_input_valid != InputValid::input_mark_search ? "" : std::to_string(this->m_id);
        }
        else if (!isdigit(stoi(this->m_operator))) {
            this->m_var1 = this->m_operator;
            this->searchItem();
            std::vector<Input> v1 = vec;
            vec.swap(v1);
            if (this->myResult.size() != 0)
                this->show_result_with_operator(&vec);
            std::string label = this->language.get_m_print_operator(this->m_input_valid);
            this->tableResult77(vec, this->m_input_valid != InputValid::input_mark_search ? this->m_index : std::to_string(this->m_id), label);
            this->m_var1 = vec.at(vec.size() - 1).m_var1;
            vec.pop_back();
            test = "+";
            continue;
        }

        test = "";
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
