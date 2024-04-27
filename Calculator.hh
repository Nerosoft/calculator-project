#include"Json.hh"
#include"Help.hh"
#include"Dialog.hh"
#include"AddSearchEdit.hh"
#include"Colors.hh"
#include"Table.hh"
#include"Main.hh"
#include"Confirm.hh"
#include"Delete.hh"

#include"Section.hh"
#include"Configration.hh"
#include"Language.hh"

#include"Input.hh"
#include"ReadWriteFile.hh"
#include"App.hh"
#include"Tables.hh"
#include"InputValue.hh"
class Calculator : public Section{
public:
    Calculator(){
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->menu.push_back({this->myInput.language.m_print_screen107, "menu_exit"});
    }
    void display_result();
private:
    std::string add = "nero-soft";
    std::string pos;
    std::string item = "";
    std::string option = "";
    std::string var = "nero-soft";
    std::string var2 = "";
    std::string search = "nero-soft";
    InputValue myInput;
    InputValue myInput_select;
    InputValue myInput_delete;      
    InputValue myInput_edit;        
    InputValue myInput_add;      
    InputValue myInput_search; 
    std::vector<std::vector<std::string>> menu;
    HANDLE hConsole;
    void addResult(std::vector<std::vector<Input>> result);
    void init_input(MenuEdit menu_edit);
    bool isValidInt22(MenuEdit menu_edit, std::string* input_value);
    bool isValidIntegr(int& value, MenuEdit section);
};


void Calculator::addResult(std::vector<std::vector<Input>> result) {
    App::write_result(result, this->myInput.m_json);
}

void Calculator::display_result() {
    this->myInput = InputValue(nullptr);//main
    do {
        if (item == this->myInput.language.m_input_key102) {//search
            int menu_size = menu.size();
            for (int i = 0; i < menu_size; i++)
                if (menu[i][0] == this->myInput.language.m_print_screen102) {
                    InputValid input_valid = this->myInput.m_input_valid;
                    search = this->myInput.add_search_ubdate(search);
                    break;
                }
                else if (i + 1 == menu.size()) {
                    InputValid input_valid = this->myInput.m_input_valid;
                    search = this->myInput.add_search_ubdate(search);
                    this->menu.push_back({ this->myInput.language.m_print_screen102, "menu_search" });
                }
            if (search == this->myInput.language.m_input_menu102)
                this->isValidInt22(MenuEdit::search, &search);
            else {
                int id = stoi(search);
                std::vector<Input>vec = this->myInput.search_by_id(id);
                std::string label = this->myInput.language.m_print_statement_confirm102;
                int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                this->myInput.tableResult77(vec, search, label);
                this->myInput.print_statement(label, color_label, &search);
                if (isValidInt22(MenuEdit::message101, &search)) {
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm102;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                    this->myInput.print_statement(label, color_label);
                    int id = this->myInput.m_id;
                    std::string key = this->myInput.language.m_input_key102;
                    this->myInput_search = InputValue(key, false, nullptr);//search
                    if (pos != std::to_string(id)) {// for change pos value
                        this->myInput = InputValue(&option, std::to_string(id), &item);//confirm
                        pos = "";
                    }
                    else {// no change my pos value
                        std::string value = this->myInput_edit.m_var1;
                        std::string m_operator = this->myInput_edit.m_operator;
                        std::vector<Input> vec = this->myInput_edit.vec;
                        std::string test = this->myInput_edit.test;
                        std::string m_pos = pos;
                        this->myInput = InputValue(&option, m_pos, value, m_operator, vec, test, &item);//confirm
                    }
                }
                else if (search != this->myInput.language.m_input_menu102)
                    this->myInput.vec.pop_back();
            }
        }
        else if (item == this->myInput.language.m_input_key101) {//add
            int menu_size = menu.size();
            for (int i = 0; i < menu_size; i++)
                if (menu[i][0] == this->myInput.language.m_print_screen101) {
                    InputValid input_valid = this->myInput.m_input_valid;
                    std::string index = this->myInput.m_index;
                    add = this->myInput.add_search_ubdate(add);
                    break;
                }
                else if (i + 1 == menu.size()) {
                    InputValid input_valid = this->myInput.m_input_valid;
                    std::string index = this->myInput.m_index;
                    add = this->myInput.add_search_ubdate(add);
                    this->menu.push_back({ this->myInput.language.m_print_screen101, "menu_add" });
                }
            if (add == this->myInput.language.m_input_menu101) {
                this->isValidInt22(MenuEdit::add, &add);
            }
            else {
                std::vector<Input> v1 = this->myInput.vec;
                std::string label = this->myInput.language.m_print_statement_confirm101;
                int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                std::string index = this->myInput.m_index;
                this->myInput.tableResult77(v1, index, label);
                this->myInput.print_statement(label, color_label, &add);
                if (isValidInt22(MenuEdit::message102, &add)) {
                    std::vector<Input>m_vec = this->myInput.vec;
                    this->myInput.myResult.push_back(m_vec);
                    this->addResult(this->myInput.myResult);
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm101;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                    this->myInput.print_statement(label, color_label);
                    std::string key = item;
                    this->myInput = InputValue(key, true, nullptr); //add
                    this->myInput_search.m_id = this->myInput_search.m_id != 0 ? this->myInput_search.m_id + 1 : this->myInput_search.m_id;
                    pos = pos != "" ? std::to_string(stoi(pos) + 1) : pos;
                }
                else if (add != this->myInput.language.m_input_menu101)
                    this->myInput.vec.pop_back();
                
            }
        }
        else if (item != "") {
            if (pos == "") {
                pos = item;
                 // init confirm when go to confirm from main menu
                //  update edit and send new pos value
                this->myInput_edit = InputValue(nullptr, nullptr, pos);//edit
            }
            else
                item = pos;
            if (option == this->myInput.language.m_input_key104) {//delete
                int menu_size = menu.size();
                for (int i = 0; i < menu_size; i++)
                    if (menu[i][0] == this->myInput.language.m_print_screen106) {
                        break;
                    }
                    else if (i + 1 == menu.size()) {
                        this->menu.push_back({ this->myInput.language.m_print_screen106, "menu_delete" });
                    }
                std::string label = this->myInput.language.m_print_message_user103;
                int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                this->myInput.print_statement(label, color_label, &var2);
                if (this->isValidInt22(MenuEdit::message104, &var2)) {
                    std::vector<std::vector<Input>>temp;
                    for (int i = 0; i < this->myInput.myResult.size(); i++) {
                        if (i == this->myInput.myResult.size() - stoi(item))
                            continue;
                        temp.push_back(this->myInput.myResult.at(i));
                    }
                    this->myInput.myResult = temp;
                    this->addResult(this->myInput.myResult);
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm105;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                    this->myInput.print_statement(label, color_label);
                    std::vector<std::vector<std::string>> menu1;
                    for (int i = 0, z = 1; i < menu.size(); i++)
                        if (menu.at(i).at(0) == this->myInput.language.m_print_screen104) {
                            menu1.push_back({ this->myInput.language.m_print_screen104, "menu_select" });
                        }
                        else if (menu.at(i).at(0) == this->myInput.language.m_print_screen107) {
                            menu1.push_back({ this->myInput.language.m_print_screen107, "menu_exit" });
                        }
                        else if (menu.at(i).at(0) == this->myInput.language.m_print_screen102) {//temp
                            menu1.push_back({ this->myInput.language.m_print_screen102, "menu_search" });
                            if (this->myInput.myResult.size() == 0 || this->myInput_search.m_id == stoi(pos)) {
                                std::string key = this->myInput.language.m_input_key102;
                                this->myInput_search = InputValue(key, false, search != "search" ? nullptr : &search);//search
                                //search = "";
                            }
                            else
                                this->myInput_search.m_id = this->myInput_search.m_id != 0  ?  this->myInput_search.m_id - 1 : this->myInput_search.m_id;
                        }
                        else if (menu.at(i).at(0) == this->myInput.language.m_print_screen101) {
                            menu1.push_back({ this->myInput.language.m_print_screen101, "menu_add" });
                        }
                        pos = "";
                    this->myInput = InputValue(&item);//main
                    menu = menu1;
                }

            }//edit
            else if (option == this->myInput.language.m_input_key103) {
                int menu_size = menu.size();
                for (int i = 0; i < menu_size; i++)
                    if (menu[i][0] == this->myInput.language.m_print_screen103) {
                        InputValid input_valid = this->myInput.m_input_valid;
                        var = this->myInput.add_search_ubdate(var);
                        break;
                    }
                    else if (i + 1 == menu.size()) {
                        InputValid input_valid = this->myInput.m_input_valid;
                        var = this->myInput.add_search_ubdate(var);
                        this->menu.push_back({ this->myInput.language.m_print_screen103, "menu_update" });
                    }
                if (var == this->myInput.language.m_input_menu103)
                    isValidInt22(MenuEdit::update_item, &var);
                else {
                    std::vector<Input> vec = this->myInput.vec;
                    std::string index = this->myInput.m_index;
                    std::string label = this->myInput.language.m_print_statement_confirm103;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                    this->myInput.tableResult77(vec, index, label);
                    this->myInput.print_statement(label, color_label, &var);
                    if (isValidInt22(MenuEdit::message103, &var)) {
                        std::vector<std::vector<Input>> m_result = this->myInput.myResult;
                        int m_index = m_result.size() - stoi(item);
                        std::vector<Input> m_vec = this->myInput.vec;
                        m_result.at(m_index) = m_vec;
                        this->myInput.myResult = m_result;
                        this->addResult(this->myInput.myResult);
                        std::string label = this->myInput.language.m_print_successfully_statement_message_confirm103;
                        int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                        this->myInput.print_statement(label, color_label);
                        std::string index = pos;


                       this->myInput_edit.vec.pop_back();
                       this->myInput_edit.m_operator = "";

                       this->myInput = InputValue(&option, index, &item);//confirm
                     

                        if (this->myInput_search.m_id == stoi(pos)) {
                            std::string key = this->myInput.language.m_input_key102;
                                this->myInput_search = InputValue(key, false, search != "search" ? nullptr : &search);//search
                        }
                    }
                    else if (var != this->myInput.language.m_input_menu103)
                        this->myInput.vec.pop_back();
                }
            }
            else {
                int menu_size = menu.size();
                for (int i = 0; i < menu_size; i++)
                    if (menu[i][0] == this->myInput.language.m_print_screen105) {
                        break;
                    }
                    else if (i + 1 == menu.size()) {
                        this->menu.push_back({ this->myInput.language.m_print_screen105, "menu_option" });
                    }
                std::string label = this->myInput.language.m_print_message_user102;
                int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                this->myInput.print_statement(label, color_label, &option);
                this->isValidInt22(MenuEdit::chose_operation, &option);
            }
        }
        else {
            int menu_size = menu.size();
            for (int i = 0; i < menu_size; i++)
                if (menu[i][0] == this->myInput.language.m_print_screen104) {
                    break;
                }
                else if (i + 1 == menu.size()) {
                    this->menu.push_back({ this->myInput.language.m_print_screen104, "menu_select" });
                }
            std::string label = this->myInput.language.m_print_message_user101;
            int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, &item);
            isValidInt22(MenuEdit::first_opration, &item);
        }
    } while (true);
}

void Calculator::init_input(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::add:
    case Section::MenuEdit::message102:
        this->myInput_add = this->myInput;
        break;
    case Section::MenuEdit::search:
    case Section::MenuEdit::message101:
        this->myInput_search = this->myInput;
        break;
    case Section::MenuEdit::update_item:
    case Section::MenuEdit::message103:
        this->myInput_edit = this->myInput;
        break;
    case Section::MenuEdit::first_opration:
        this->myInput_select = this->myInput;
        break;
    case Section::MenuEdit::message104:
        this->myInput_delete = this->myInput;
        break;
    }
}
bool Calculator::isValidInt22(MenuEdit menu_edit, std::string* input_value = nullptr) {
    this->init_input(menu_edit);
    do {
        if (*input_value == this->myInput.language.get_m_input_menu(menu_edit)) {
            std::string label = this->myInput.language.get_m_print_menu_statement(menu_edit);
            std::string id = this->myInput.language.get_id_menu(menu_edit);
            int i;
            this->myInput.display_table_menu(menu, id, label, menu_edit);
            int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_menu_statement);
            this->myInput.print_statement(label, color_label, &i);
            if(i == 1)
                exit(0);
            else if (!isValidIntegr(i, menu_edit) && i <= this->menu.size() && i > 0 ) {
                Section::MenuEdit m_menu_edit = this->myInput.language.get_menu_edit(this->menu.at(i - 1).at(0), menu_edit);
                std::string label = menu_edit != m_menu_edit ? this->myInput.language.get_m_print_menu_statement_screen(this->menu.at(i - 1).at(1))
                    : this->myInput.language.get_m_print_successfully_menu_statement(menu_edit);
                int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_menu_statement);
                this->myInput.print_statement(label, color_label);
                switch (m_menu_edit)
                {
                case Section::MenuEdit::message102:
                case Section::MenuEdit::add: {
                    std::string test = this->myInput_add.test;
                    std::vector<Input>vec = this->myInput_add.vec;
                    int space = this->myInput.my_lable_space;
                    std::string value = this->myInput_add.m_var1;
                    std::string m_operator = this->myInput_add.m_operator;
                    std::string key = this->myInput_add.language.m_input_key101;
                    this->myInput = InputValue(key, value, m_operator, test, vec, space, &item);
                    break;
                }
                case Section::MenuEdit::message101:
                case Section::MenuEdit::search: {
                    std::string test = this->myInput_search.test;
                    std::vector<Input>vec = this->myInput_search.vec;
                    int space = this->myInput.my_lable_space;
                    std::string value = this->myInput_search.m_var1;
                    std::string m_operator = this->myInput_search.m_operator;
                    std::string key = this->myInput.language.m_input_key102;
                    int id = this->myInput_search.m_id;
                    std::string m_index = this->myInput_search.m_index;
                    this->myInput = InputValue(key, value, m_operator, test, vec, space, &item, id);
                    break;
                }
                case Section::MenuEdit::message103:
                case Section::MenuEdit::update_item: {
                    std::string test = this->myInput_edit.test;
                    std::string value = this->myInput_edit.m_var1;
                    std::string m_operator = this->myInput_edit.m_operator;
                    std::vector<Input> vec = this->myInput_edit.vec;
                    int space = this->myInput.my_lable_space;
                    std::string index = pos;
                    this->myInput = InputValue(index, space, test, value, m_operator, vec, &item, &option);
                    break;
                }
                case Section::MenuEdit::first_opration:
                    this->myInput = InputValue(&item);
                    break;
                
                case Section::MenuEdit::message104: {
                    std::string index = this->pos;
                    std::string key_delete = this->myInput.language.m_input_key104;
                    this->myInput = InputValue(index, &option, &item);//delete
                    break;
                }
                case Section::MenuEdit::chose_operation: {
                    std::string value = this->myInput_edit.m_var1;
                    std::string m_operator = this->myInput_edit.m_operator;
                    std::vector<Input> vec = this->myInput_edit.vec;
                    std::string test = this->myInput_edit.test;
                    std::string m_pos = pos;
                    this->myInput = InputValue(&option, m_pos, value, m_operator, vec, test, menu_edit != Section::MenuEdit::add && menu_edit != Section::MenuEdit::message102 && menu_edit != Section::MenuEdit::search && menu_edit != Section::MenuEdit::message101 ? nullptr : &item);//confirm
                    break;
                }
                
                }
                add = menu_edit == MenuEdit::add ? "" : add;
                search = menu_edit == MenuEdit::search ? "" : search;
                var = menu_edit == MenuEdit::update_item ? "" : var;
                return false;
            }
        }
        else if (*input_value == this->myInput.language.get_m_input_help(menu_edit)) {
            std::string label = this->myInput.language.get_m_print_help(menu_edit);
            int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_help);
            this->myInput.print_statement(label, color_label);

            label = this->myInput.language.get_m_print_message_user(menu_edit);
            color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, input_value);
        }
        else if (*input_value == this->myInput.language.m_input_key101 && menu_edit == MenuEdit::first_opration
            || *input_value == this->myInput.language.m_input_key102 && menu_edit == MenuEdit::first_opration
            || *input_value == this->myInput.language.m_input_key103 && menu_edit == MenuEdit::chose_operation
            || *input_value == this->myInput.language.m_input_key104 && menu_edit == MenuEdit::chose_operation) {
            Section::InputKey input_key = this->myInput.language.get_section(*input_value, add, search, var);
            std::string label = this->myInput.language.get_m_print_successfully_statement_confirm(input_key);
            int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_confirm);
            this->myInput.print_statement(label, color_label);
            switch (input_key)
            {
            case Section::InputKey::addition: {
               
                std::string test = this->myInput_add.test;
                std::vector<Input>vec = this->myInput_add.vec;
                int space = this->myInput.my_lable_space;
                std::string value = this->myInput_add.m_var1;
                std::string m_operator = this->myInput_add.m_operator;
                std::string key = this->myInput.language.m_input_key101;
                this->myInput = InputValue(key, value, m_operator, test, vec, space, nullptr);
                break;
            }

            case Section::InputKey::search: {
                std::string test = this->myInput_search.test;
                std::vector<Input>vec = this->myInput_search.vec;
                int space = this->myInput.my_lable_space;
                std::string value = this->myInput_search.m_var1;
                std::string m_operator = this->myInput_search.m_operator;
                std::string key = this->myInput.language.m_input_key102;
                int id = this->myInput_search.m_id;
                this->myInput = InputValue(key, value, m_operator, test, vec, space, nullptr, id);
                break;
            }

            case Section::InputKey::edit: {
                std::string test = this->myInput_edit.test;
                std::string value = this->myInput_edit.m_var1;
                std::string m_operator = this->myInput_edit.m_operator;
                std::vector<Input> vec = this->myInput_edit.vec;
                int space = this->myInput.my_lable_space;
                std::string index = pos;
                this->myInput = InputValue(index, space, test, value, m_operator, vec, nullptr, nullptr);
                break;
            }

            case Section::InputKey::deletion: {
                std::string index = this->pos;
                this->myInput = InputValue(index, nullptr, nullptr);
                break;
            }

            case Section::InputKey::first_call_add: {
                std::string key = item;
                this->myInput = InputValue(key, true, nullptr);// add
                break;
            }

            case Section::InputKey::first_call_search: {
                std::string key = item;
                this->myInput = InputValue(key, true, nullptr);//search
                break;
            }

            case Section::InputKey::first_call_edit: {
                this->myInput = InputValue(nullptr, nullptr, pos);
                break;
            }
            }

            return false;
        }

        else if (*input_value == this->myInput.language.get_m_input_y(menu_edit) && menu_edit == Section::MenuEdit::message102
            || *input_value == this->myInput.language.get_m_input_y(menu_edit) && menu_edit == Section::MenuEdit::message101
            || *input_value == this->myInput.language.get_m_input_y(menu_edit) && menu_edit == Section::MenuEdit::message103
            || *input_value == this->myInput.language.get_m_input_y(menu_edit) && menu_edit == Section::MenuEdit::message104) {
            return true;
        }
        else if (*input_value == this->myInput.language.get_m_input_n(menu_edit) && menu_edit == Section::MenuEdit::message102
            || *input_value == this->myInput.language.get_m_input_n(menu_edit) && menu_edit == Section::MenuEdit::message101
            || *input_value == this->myInput.language.get_m_input_n(menu_edit) && menu_edit == Section::MenuEdit::message103
            || *input_value == this->myInput.language.get_m_input_n(menu_edit) && menu_edit == Section::MenuEdit::message104) {
            return false;
        }
        else if (menu_edit == Section::MenuEdit::add || menu_edit == Section::MenuEdit::search || menu_edit == Section::MenuEdit::update_item
            || menu_edit == Section::MenuEdit::chose_operation || menu_edit == Section::MenuEdit::message101 || menu_edit == Section::MenuEdit::message102
            || menu_edit == Section::MenuEdit::message103 || menu_edit == Section::MenuEdit::message104) {
            std::string label = this->myInput.language.get_m_print_error_statement_confirm(menu_edit);
            int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_error_statement_confirm);
            this->myInput.print_statement(label, color_label);
            label = this->myInput.language.get_m_print_statement_confirm(menu_edit);
            color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, input_value);
        }
        else
            try {
            for (int i = 0; i < input_value->size(); i++) {
                if (this->myInput.myResult.size() == 0 || input_value ->length()>= MAX_SIZE_STRING || !isdigit(input_value->at(i)) || stoi(*input_value) > this->myInput.myResult.size() || stoi(*input_value) < 1) {
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm104;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_error_statement_confirm);
                    this->myInput.print_statement(label, color_label);
                    label = this->myInput.language.get_m_print_statement_confirm(menu_edit);
                    color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_statement_confirm);
                    this->myInput.print_statement(label, color_label, input_value);
                    break;//for exit loop
                }
                else if (i + 1 == input_value->size() && pos != *input_value) {// for change pos value
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm104;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                    this->myInput.print_statement(label, color_label);
                    std::string value = *input_value;
                    this->myInput = InputValue(&option, value, nullptr);//confirm
                    pos = "";
                    return false;
                }
                else if (i + 1 == input_value->size()) {// no change pos value
                    std::string label = this->myInput.language.m_print_successfully_statement_message_confirm104;
                    int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_successfully_statement_message_confirm);
                    this->myInput.print_statement(label, color_label);
                    std::string value = this->myInput_edit.m_var1;
                    std::string m_operator = this->myInput_edit.m_operator;
                    std::vector<Input> vec = this->myInput_edit.vec;
                    std::string test = this->myInput_edit.test;
                    std::string m_pos = pos;
                    this->myInput = InputValue(&option, m_pos, value, m_operator, vec, test, nullptr);//confirm
                    return false;
                }

            }
        }
        catch (std::exception& e) {

        }
    } while (true);
}

bool Calculator::isValidIntegr(int& value, MenuEdit section) {
    while (true) {
        if (std::cin.good() && value > 0 && value <= menu.size()) {
            return false;
        }
        else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        std::string label = this->myInput.language.get_m_print_error_menu_statement(section);
        int color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_error_menu_statement);
        this->myInput.print_statement(label, color_label);
        label = this->myInput.language.get_m_print_menu_statement(section);
        color_label = this->myInput.get_color_by_name(this->myInput.language.m_color_menu_statement);
        this->myInput.print_statement(label, color_label, &value);
    }
}
