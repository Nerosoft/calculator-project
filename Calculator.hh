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
#include"Input.hh"
#include"App.hh"
#include"InitObject.hh"
#include"ReadFile.hh"
#include"Language.hh"


#include"Tables.hh"
#include"InputValue.hh"
class Calculator : Section{
public:
    Calculator(){
        this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->menu.push_back({this->myInput.m_print_screen107, "menu_exit"});
    }
    void isValidInt22(MenuEdit menu_edit);

private:
    std::string add = "nero-soft";
    std::string pos;
    std::string item = "go_main";
    std::string option = "";
    std::string var = "";
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
    void init_input(MenuEdit menu_edit);
    bool isValidIntegr(int& value, MenuEdit section);
    std::string menu_exist(MenuEdit menu_edit);
    void set_add();
    void set_edit();
    void set_search();
    void pop_array();
    std::string reset_search();

    bool valid_number();
    std::string* get_input_value(MenuEdit menu_edit);
    void get_input_add();
    void get_input_search();
    void get_confirm_input();
    void get_edit_input();
    void get_delete();
    void get_main_input();
    void deleting_item();
    Section::MenuEdit get_key_menu(MenuEdit menu_edit);
    InputValue set_search_add_input(std::string key, bool state, std::string* ptr_search);
    Section::MenuEdit get_menu_edit(std::string menu, Section::MenuEdit menu_edit);
    std::string get_m_print_menu_statement_screen(std::string id);

    std::string get_m_print_successfully_menu_statement(MenuEdit menu_edit);
    std::string get_m_menu_title(MenuEdit menu_edit);
    std::string get_m_print_menu_statement(MenuEdit menu_edit);
    std::string get_m_print_error_menu_statement(MenuEdit menu_edit);
    std::string get_id_menu(MenuEdit menu_edit);
    std::string get_m_print_statement_confirm_user(MenuEdit menu_edit);
    std::string get_m_print_color_confirm_user(MenuEdit menu_edit);
    std::string get_m_print_error_statement_confirm(MenuEdit menu_edit);
    void reset_pos();
    InputValue get_input_confirm();
    void get_confirm();

    void setup_menu(MenuEdit menu_edit);
    void get_add_search_edit(MenuEdit* menu_edit);
};
void Calculator::get_add_search_edit(MenuEdit* menu_edit) {
    int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_confirm);
    if (item == this->myInput.m_input_key101 && *menu_edit == MenuEdit::first_opration) {
        std::string label = this->myInput.m_print_successfully_statement_confirm101;
        this->myInput.print_statement(label, color_label);
        this->get_input_add();//----      
        //--------------------------------------------
        *menu_edit = this->menu_exist(MenuEdit::add) == "" ? MenuEdit::message102 : MenuEdit::add;
    }
    else if (*menu_edit == MenuEdit::first_opration) {
        std::string label = this->myInput.m_print_successfully_statement_confirm102;
        this->myInput.print_statement(label, color_label);
        this->get_input_search();//------
        //-------------------------------------
        *menu_edit = this->menu_exist(MenuEdit::search) == "" ? MenuEdit::message101 : MenuEdit::search;
    }
    else {
        std::string label = this->myInput.m_print_successfully_statement_confirm103;
        this->myInput.print_statement(label, color_label);
        this->get_edit_input();
        //----------------------------------
        *menu_edit = this->menu_exist(MenuEdit::update_item) == "" ? MenuEdit::message103 : MenuEdit::update_item;
    }
    this->init_input(*menu_edit);//save input add search edit
}
void Calculator::setup_menu(MenuEdit menu_edit) {
    add = menu_edit == MenuEdit::add ? "" : add;
    search = menu_edit == MenuEdit::search ? "" : search;
    var = menu_edit == MenuEdit::update_item ? "" : var;
}
void Calculator::get_confirm() {
    std::string index = this->myInput_search.m_id == stoi(pos) && this->myInput.get_text_search(this->myInput_search.vec) != this->myInput.get_text_search(this->myInput_edit.vec) ? this->reset_search() : pos;
    this->myInput = InputValue("confirm", index);//confirm
}
InputValue Calculator::get_input_confirm() {
    std::string value = this->myInput_edit.m_var1;
    std::string m_operator = this->myInput_edit.m_operator;
    std::vector<Input> vec = this->myInput_edit.vec;
    std::string test = this->myInput_edit.test;
    this->myInput = InputValue(pos, value, m_operator, vec, test);//confirm
    return this->myInput;
}
//----------------------
void Calculator::reset_pos() {
    if (pos != item) {
        pos = item;
        this->myInput_edit = InputValue("edit", item);//call input edit when go to edit from any app using menu
        var = var != this->myInput.m_input_menu103 ? var : "";
    }
}
std::string Calculator::get_m_print_error_statement_confirm(MenuEdit menu_edit) {
    if (menu_edit == Section::MenuEdit::add || menu_edit == Section::MenuEdit::message102)
        return this->myInput.m_print_error_statement_confirm101;
    else if (menu_edit == Section::MenuEdit::search || menu_edit == Section::MenuEdit::message101)
        return this->myInput.m_print_error_statement_confirm102;
    else if (menu_edit == Section::MenuEdit::update_item || menu_edit == Section::MenuEdit::message103)
        return this->myInput.m_print_error_statement_confirm103;
    else if (menu_edit == Section::MenuEdit::first_opration)
        return this->myInput.m_print_error_message_user101;
    else if (menu_edit == Section::MenuEdit::message104)
        return this->myInput.m_print_error_message_user103;
    //Section::MenuEdit::chose_operation:
    else
        return this->myInput.m_print_error_message_user102;
}
std::string Calculator::get_m_print_color_confirm_user(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::first_opration)
        return this->myInput.m_color_main;
    else if (menu_edit == MenuEdit::chose_operation)
        return this->myInput.m_color_confirm;
    else
        return this->myInput.m_color_statement_confirm;
}
std::string Calculator::get_m_print_statement_confirm_user(MenuEdit menu_edit) {
    if (menu_edit == Section::MenuEdit::add || menu_edit == Section::MenuEdit::message102)
        return this->myInput.m_print_statement_confirm101;
    else if (menu_edit == Section::MenuEdit::search || menu_edit == Section::MenuEdit::message101)
        return this->myInput.m_print_statement_confirm102;
    else if (menu_edit == Section::MenuEdit::update_item || menu_edit == Section::MenuEdit::message103)
        return this->myInput.m_print_statement_confirm103;
    else if (menu_edit == Section::MenuEdit::first_opration)
        return this->myInput.m_print_message_user101;
    else if (menu_edit == Section::MenuEdit::message104)
        return this->myInput.m_print_statement_confirm104;
    //Section::MenuEdit::chose_operation:
    else
        return this->myInput.m_print_message_user102;
}
std::string Calculator::get_id_menu(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::message102 || menu_edit == MenuEdit::add)
        return "menu_add";
    else if (menu_edit == MenuEdit::message101 || menu_edit == MenuEdit::search)
        return "menu_search";
    else if (menu_edit == MenuEdit::message103 || menu_edit == MenuEdit::update_item)
        return "menu_update";
    else if (menu_edit == MenuEdit::first_opration)
        return "menu_select";
    else if (menu_edit == MenuEdit::message104)
        return "menu_delete";
    //menu_edit == MenuEdit::chose_operation
    else
        return "menu_option";
}
std::string Calculator::get_m_print_error_menu_statement(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::message102 || menu_edit == MenuEdit::add)
        return this->myInput.m_print_error_menu_statement101;
    else if (menu_edit == MenuEdit::message101 || menu_edit == MenuEdit::search)
        return this->myInput.m_print_error_menu_statement102;
    else if (menu_edit == MenuEdit::message103 || menu_edit == MenuEdit::update_item)
        return this->myInput.m_print_error_menu_statement103;
    else if (menu_edit == MenuEdit::first_opration)
        return this->myInput.m_print_error_menu_statement104;
    else if (menu_edit == MenuEdit::chose_operation)
        return this->myInput.m_print_error_menu_statement105;
    //MenuEdit::message104:
    else
        return this->myInput.m_print_error_menu_statement106;
}
std::string Calculator::get_m_print_menu_statement(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::message102 || menu_edit == MenuEdit::add)
        return this->myInput.m_print_menu_statement101;
    else if (menu_edit == MenuEdit::message101 || menu_edit == MenuEdit::search)
        return this->myInput.m_print_menu_statement102;
    else if (menu_edit == MenuEdit::message103 || menu_edit == MenuEdit::update_item)
        return this->myInput.m_print_menu_statement103;
    else if (menu_edit == MenuEdit::first_opration)
        return this->myInput.m_print_menu_statement104;
    else if (menu_edit == MenuEdit::chose_operation)
        return this->myInput.m_print_menu_statement105;
    //MenuEdit::message104:
    else
        return this->myInput.m_print_menu_statement106;
}
std::string Calculator::get_m_menu_title(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::message102 || menu_edit == MenuEdit::add)
        return this->myInput.m_menu_title101;
    else if (menu_edit == MenuEdit::message101 || menu_edit == MenuEdit::search)
        return this->myInput.m_menu_title102;
    else if (menu_edit == MenuEdit::message103 || menu_edit == MenuEdit::update_item)
        return this->myInput.m_menu_title103;
    else if (menu_edit == MenuEdit::first_opration)
        return this->myInput.m_menu_title104;
    else if (menu_edit == MenuEdit::chose_operation)
        return this->myInput.m_menu_title105;
    //MenuEdit::message104:
    else
        return this->myInput.m_menu_title106;
}
std::string Calculator::get_m_print_successfully_menu_statement(MenuEdit menu_edit) {
    if (menu_edit == Section::MenuEdit::message102 || menu_edit == Section::MenuEdit::add)
        return this->myInput.m_print_successfully_menu_statement101;
    else if (menu_edit == Section::MenuEdit::message101 || menu_edit == Section::MenuEdit::search)
        return this->myInput.m_print_successfully_menu_statement102;
    else if (menu_edit == Section::MenuEdit::message103 || menu_edit == Section::MenuEdit::update_item)
        return this->myInput.m_print_successfully_menu_statement103;
    else if (menu_edit == Section::MenuEdit::first_opration)
        return this->myInput.m_print_successfully_menu_statement104;
    else if (menu_edit == Section::MenuEdit::message104)
        return this->myInput.m_print_successfully_menu_statement106;
    //Section::MenuEdit::chose_operation:
    else
        return this->myInput.m_print_successfully_menu_statement105;
}
std::string Calculator::get_m_print_menu_statement_screen(std::string id) {
    if (id == "menu_search")
        return this->myInput.m_print_successfully_menu_statement_search_screen;
    else if (id == "menu_add")
        return this->myInput.m_print_successfully_menu_statement_add_screen;
    else if (id == "menu_delete")
        return this->myInput.m_print_successfully_menu_statement_delete_screen;
    else if (id == "menu_select")
        return this->myInput.m_print_successfully_menu_statement_main_screen;
    else if (id == "menu_option")
        return this->myInput.m_print_successfully_menu_statement_confirm_screen;
    else //if (id == "menu_update")
        return this->myInput.m_print_successfully_menu_statement_edit_screen;
}
Section::MenuEdit Calculator::get_menu_edit(std::string menu, Section::MenuEdit menu_edit) {
    if (menu == this->myInput.m_print_screen101)
        return menu_edit != Section::MenuEdit::add ? Section::MenuEdit::message102 : Section::MenuEdit::add;
    else if (menu == this->myInput.m_print_screen102)
        return  menu_edit != Section::MenuEdit::search ? Section::MenuEdit::message101 : Section::MenuEdit::search;
    else if (menu == this->myInput.m_print_screen103)
        return menu_edit != Section::MenuEdit::update_item ? Section::MenuEdit::message103 : Section::MenuEdit::update_item;
    else if (menu == this->myInput.m_print_screen104)
        return Section::MenuEdit::first_opration;
    else if (menu == this->myInput.m_print_screen105)
        return Section::MenuEdit::chose_operation;
    else //if (menu == this->m_print_screen106)
        return Section::MenuEdit::message104;
}
bool Calculator::valid_number() {
    try {
        for (int i = 0; i < item.size(); i++)
            if (this->myInput.myResult.size() == 0 || item.length() >= MAX_SIZE_STRING || !isdigit(item[i]) || stoi(item) > this->myInput.myResult.size() || stoi(item) < 1)
                return false;

        return true;
    }
    catch (std::exception& e) {

    }
}
std::string* Calculator::get_input_value(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::add || menu_edit == MenuEdit::message102)
        return &add;
    else if (menu_edit == MenuEdit::search || menu_edit == MenuEdit::message101)
        return &search;
    else if (menu_edit == MenuEdit::update_item || menu_edit == MenuEdit::message103)
        return &var;
    else if (menu_edit == MenuEdit::first_opration)
        return &item;
    else if (menu_edit == MenuEdit::chose_operation)
        return &option;
    else //delete
        return &var2;
}
void Calculator::get_input_add() {
    std::string test = this->myInput_add.test;
    std::vector<Input>vec = this->myInput_add.vec;
    int space = this->myInput.my_lable_space;
    std::string value = this->myInput_add.m_var1;
    std::string m_operator = this->myInput_add.m_operator;
    std::string key = this->myInput_add.m_input_key101;
    this->myInput = add == "nero-soft" ? InputValue(key, true, nullptr) : InputValue(key, value, m_operator, test, vec, space);
}
void Calculator::get_input_search() {
    std::string test = this->myInput_search.test;
    std::vector<Input>vec = this->myInput_search.vec;
    int space = this->myInput.my_lable_space;
    std::string value = this->myInput_search.m_var1;
    std::string m_operator = this->myInput_search.m_operator;
    std::string key = this->myInput_search.m_input_key102;
    int id = this->myInput_search.m_id;
    this->myInput = search == "nero-soft" ? InputValue(key, true, nullptr) : InputValue(key, value, m_operator, test, vec, space, id);
}
void Calculator::get_confirm_input() {
    this->myInput = pos != item ? InputValue("confirm", item) : this->get_input_confirm();//confirm
}
void Calculator::get_edit_input() {//-----------
    std::string test = this->myInput_edit.test;
    std::string value = this->myInput_edit.m_var1;
    std::string m_operator = this->myInput_edit.m_operator;
    std::vector<Input> vec = this->myInput_edit.vec;
    int space = this->myInput.my_lable_space;
    this->myInput = InputValue(pos, space, test, value, m_operator, vec);
}
void Calculator::get_delete() {
    this->myInput = InputValue("delete", pos);
}
void Calculator::get_main_input() {
    this->myInput = InputValue("main");
}
void Calculator::deleting_item() {
    std::vector<std::vector<Input>>temp;
    for (int i = 0; i < this->myInput.myResult.size(); i++) {
        if (i == this->myInput.myResult.size() - stoi(pos))
            continue;
        temp.push_back(this->myInput.myResult.at(i));
    }
    this->myInput.myResult = temp;
    this->myInput.m_write_result(this->myInput.myResult);
    std::vector<std::vector<std::string>> menu1;
    for (int i = 0, z = 1; i < menu.size(); i++)
        if (menu.at(i).at(0) == this->myInput.m_print_screen104) {
            menu1.push_back({ this->myInput.m_print_screen104, "menu_select" });
        }
        else if (menu.at(i).at(0) == this->myInput.m_print_screen107) {
            menu1.push_back({ this->myInput.m_print_screen107, "menu_exit" });
        }
        else if (menu.at(i).at(0) == this->myInput.m_print_screen102) {//temp
            menu1.push_back({ this->myInput.m_print_screen102, "menu_search" });
            if (this->myInput.myResult.size() == 0)
                this->myInput_search = this->set_search_add_input(this->myInput.m_input_key102, false, search != this->myInput.m_input_menu102 ? nullptr : &search);

            else if (this->myInput_search.m_id == stoi(pos))
                this->reset_search();
            else
                this->myInput_search.m_id = this->myInput_search.m_id != 0 ? this->myInput_search.m_id - 1 : this->myInput_search.m_id;
        }
        else if (menu.at(i).at(0) == this->myInput.m_print_screen101) {
            menu1.push_back({ this->myInput.m_print_screen101, "menu_add" });
        }
    pos = "";
    this->get_main_input();//main
    menu = menu1;
}
Section::MenuEdit Calculator::get_key_menu(MenuEdit menu_edit) {
    if (menu_edit == MenuEdit::add)
        return MenuEdit::message102;
    else if (menu_edit == MenuEdit::search)
        return MenuEdit::message101;
    else if (menu_edit == MenuEdit::update_item)
        return MenuEdit::message103;
    else if (menu_edit == MenuEdit::message102)
        return MenuEdit::add;
    else if (menu_edit == MenuEdit::message101)
        return MenuEdit::search;
    else
        return MenuEdit::update_item;
}
InputValue Calculator::set_search_add_input(std::string key, bool state, std::string* ptr_search = nullptr) {
    return InputValue(key, state, ptr_search);//search
}
std::string Calculator::reset_search() {
    this->myInput_search.m_id = 0;
    if (search == this->myInput.m_input_menu102) {
        search = "";
        this->myInput_search.vec.pop_back();
    }
    return this->pos;
}
void Calculator::pop_array() {
    this->myInput.vec.pop_back();
}
void Calculator::set_edit() {
    int m_index = this->myInput.myResult.size() - stoi(pos);
    this->myInput.myResult.at(m_index) = this->myInput.vec;
    this->myInput.m_write_result(this->myInput.myResult);
    this->get_confirm();
    this->myInput_edit.vec.pop_back();
    this->myInput_edit.m_operator = "";
}
void Calculator::set_search() {
    this->myInput_search = this->set_search_add_input(this->myInput.m_input_key102, false);
    item = std::to_string(this->myInput.m_id);
    this->get_confirm_input();
    this->reset_pos();
}
void Calculator::set_add() {
    std::vector<Input>m_vec = this->myInput.vec;
    this->myInput.myResult.push_back(m_vec);
    this->myInput.m_write_result(this->myInput.myResult);
    this->myInput = this->set_search_add_input(this->myInput.m_input_key101, true); //add
    this->myInput_search.m_id = this->myInput_search.m_id != 0 ? this->myInput_search.m_id + 1 : this->myInput_search.m_id;
    pos = pos != "" ? std::to_string(stoi(pos) + 1) : pos;
}
std::string Calculator::menu_exist(MenuEdit menu_edit) {
    int menu_size = menu.size();
    for (int i = 0; i < menu_size; i++)
        if (menu[i][0] == this->myInput.m_print_screen101 && menu_edit == MenuEdit::add) {
            add = this->myInput.add_search_ubdate(add);
            return add;
        }
        else if (menu[i][0] == this->myInput.m_print_screen102 && menu_edit == MenuEdit::search) {
            search = this->myInput.add_search_ubdate(search);
            return search;
        }
        else if (menu[i][0] == this->myInput.m_print_screen103 && menu_edit == MenuEdit::update_item) {
            var = this->myInput.add_search_ubdate(var);
            return var;
        }
        else if (menu[i][0] == this->myInput.m_print_screen104 && menu_edit == MenuEdit::first_opration ||
            menu[i][0] == this->myInput.m_print_screen105 && menu_edit == MenuEdit::chose_operation || 
            menu[i][0] == this->myInput.m_print_screen106 && menu_edit == MenuEdit::message104)
            return "";

        else if (i + 1 == menu.size() && menu_edit == MenuEdit::add) {
            add = this->myInput.add_search_ubdate(add);
            this->menu.push_back({ this->myInput.m_print_screen101, "menu_add"});
            return add;
        }
        else if (i + 1 == menu.size() && menu_edit == MenuEdit::search) {
            search = this->myInput.add_search_ubdate(search);
            this->menu.push_back({ this->myInput.m_print_screen102, "menu_search"});
            return search;
        }
        else if (i + 1 == menu.size() && menu_edit == MenuEdit::update_item) {
            var = this->myInput.add_search_ubdate(var);
            this->menu.push_back({ this->myInput.m_print_screen103, "menu_update"});
            return var;
        }
        else if (i + 1 == menu.size() && menu_edit == MenuEdit::first_opration) {
            this->menu.push_back({ this->myInput.m_print_screen104, "menu_select"});
            return "";
        }
        else if (i + 1 == menu.size() && menu_edit == MenuEdit::chose_operation) {
            this->menu.push_back({ this->myInput.m_print_screen105, "menu_option" });
            return "";
        }
        else if (i + 1 == menu.size() && menu_edit == MenuEdit::message104) {
            this->menu.push_back({ this->myInput.m_print_screen106, "menu_delete"});
            return "";
        }
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

void Calculator::isValidInt22(MenuEdit menu_edit) {
    this->get_main_input();
    this->menu_exist(MenuEdit::first_opration);
    do {     
        if (item == "go_main" && menu_edit == MenuEdit::first_opration) {
            std::string label = this->myInput.m_print_message_user101;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_main);
            this->myInput.print_statement(label, color_label, &item);
        }
        else if (option == "go_confirm" && menu_edit == MenuEdit::chose_operation) {
            std::string label = this->myInput.m_print_message_user102;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_confirm);
            this->myInput.print_statement(label, color_label, &option);
        }
        else if (var2 == "go_delete" && menu_edit == MenuEdit::message104) {
            std::string label = this->myInput.m_print_statement_confirm104;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, &var2);
        }
        else if (menu_edit == MenuEdit::add && add == this->myInput.m_input_menu101 || menu_edit == MenuEdit::message102 && add == this->myInput.m_input_menu101 || menu_edit == MenuEdit::search && search == this->myInput.m_input_menu102 || menu_edit == MenuEdit::message101 && search == this->myInput.m_input_menu102 || menu_edit == MenuEdit::update_item && var == this->myInput.m_input_menu103 || menu_edit == MenuEdit::message103 && var == this->myInput.m_input_menu103 || menu_edit == MenuEdit::first_opration && item == this->myInput.m_input_menu104 || menu_edit == MenuEdit::chose_operation && option == this->myInput.m_input_menu105 || menu_edit == MenuEdit::message104 && var2 == this->myInput.m_input_menu106) {
            MenuEdit menu_edit2 = menu_edit;
            std::string label = this->get_m_print_menu_statement(menu_edit);
            std::string id = this->get_id_menu(menu_edit);
            int i;
            this->myInput.display_table_menu(menu, id, label, this->get_m_menu_title(menu_edit));
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_menu_statement);
            this->myInput.print_statement(label, color_label, &i);
            if (!isValidIntegr(i, menu_edit) && i == 1)
                return;
            else{
                Section::MenuEdit m_menu_edit = this->get_menu_edit(this->menu.at(i - 1).at(0), menu_edit);
                std::string label = menu_edit != m_menu_edit ? this->get_m_print_menu_statement_screen(this->menu.at(i - 1).at(1)) : this->get_m_print_successfully_menu_statement(menu_edit);
                int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_menu_statement);
                this->myInput.print_statement(label, color_label);
                switch (m_menu_edit)
                {
                case Section::MenuEdit::message102:
                case Section::MenuEdit::add:
                    this->get_input_add();//----
                    this->setup_menu(menu_edit);
                    add = this->myInput.add_search_ubdate(add);
                    menu_edit = add != "" ? MenuEdit::add : MenuEdit::message102;
                    this->init_input(menu_edit);//save input add
                    continue;
                case Section::MenuEdit::message101:
                case Section::MenuEdit::search:
                    this->get_input_search();//------
                    this->setup_menu(menu_edit);
                    search = this->myInput.add_search_ubdate(search);
                    menu_edit = search != "" ? MenuEdit::search : MenuEdit::message101;
                    this->init_input(menu_edit);//save input search
                    continue;
                case Section::MenuEdit::message103:
                case Section::MenuEdit::update_item:
                    this->get_edit_input();
                    this->setup_menu(menu_edit);
                    var = this->myInput.add_search_ubdate(var);
                    menu_edit = var != "" ? MenuEdit::update_item : MenuEdit::message103;
                    this->init_input(menu_edit);//save input edit
                    continue;
                case Section::MenuEdit::first_opration: {
                    this->get_main_input();
                    item = "go_main";
                    menu_edit = MenuEdit::first_opration;
                    break;
                }
                case Section::MenuEdit::message104:
                    this->get_delete();
                    var2 = "go_delete";
                    menu_edit = MenuEdit::message104;
                    break;
                
                case Section::MenuEdit::chose_operation:
                    this->get_input_confirm();
                    option = "go_confirm";
                    menu_edit = MenuEdit::chose_operation;
                    break;
                }
                this->setup_menu(menu_edit2);
                this->init_input(menu_edit);//save input main confirm delete
            }
        }
        else if (menu_edit == MenuEdit::add && add == this->myInput.m_input_help101 || menu_edit == MenuEdit::message102 && add == this->myInput.m_input_help101 || menu_edit == MenuEdit::search && search == this->myInput.m_input_help102 || menu_edit == MenuEdit::message101 && search == this->myInput.m_input_help102 || menu_edit == MenuEdit::update_item && var == this->myInput.m_input_help103 || menu_edit == MenuEdit::message103 && var == this->myInput.m_input_help103 || menu_edit == MenuEdit::first_opration && item == this->myInput.m_input_help104 || menu_edit == MenuEdit::chose_operation && option == this->myInput.m_input_help105 || menu_edit == MenuEdit::message104 && var2 == this->myInput.m_input_help106) {
            //no save input in help
            std::string label = this->myInput.get_m_print_help(menu_edit);
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_help);
            this->myInput.print_statement(label, color_label);

            label = this->get_m_print_statement_confirm_user(menu_edit);
            color_label = this->myInput.get_color_by_name(this->get_m_print_color_confirm_user(menu_edit));
            this->myInput.print_statement(label, color_label, this->get_input_value(menu_edit));
        }
        else if (option == this->myInput.m_input_key103 && menu_edit == MenuEdit::chose_operation || item == this->myInput.m_input_key101 && menu_edit == MenuEdit::first_opration || item == this->myInput.m_input_key102 && menu_edit == MenuEdit::first_opration) {
            this->get_add_search_edit(&menu_edit);
            continue;
        }
        else if (this->valid_number() && menu_edit == MenuEdit::first_opration || var2 == this->myInput.m_input_n104 && menu_edit == Section::MenuEdit::message104) {
            item = this->valid_number() ? item :pos;
            std::string label = menu_edit != MenuEdit::message104 ? this->myInput.m_print_successfully_statement_message_confirm104 : this->myInput.m_print_successfully_statement_confirm105;
            int color_label = this->myInput.get_color_by_name(menu_edit != MenuEdit::message104 ? this->myInput.m_color_successfully_statement_message_confirm : this->myInput.m_color_successfully_statement_confirm);
            this->myInput.print_statement(label, color_label);
            this->get_confirm_input();
            this->reset_pos();//pos""
            menu_edit = MenuEdit::chose_operation;
            this->init_input(menu_edit);//save input confirm
            //---------------------------------
            this->menu_exist(menu_edit);
            label = this->myInput.m_print_message_user102;
            color_label = this->myInput.get_color_by_name(this->myInput.m_color_confirm);
            this->myInput.print_statement(label, color_label, &option);
        }
        else if (option == this->myInput.m_input_key104 && menu_edit == MenuEdit::chose_operation) {
            std::string label = this->myInput.m_print_successfully_statement_confirm104;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_confirm);
            this->myInput.print_statement(label, color_label);
            this->get_delete();
            menu_edit = MenuEdit::message104;
            this->init_input(menu_edit);//save input delete
            //---------------------------
            this->menu_exist(menu_edit);
            label = this->myInput.m_print_statement_confirm104;
            color_label = this->myInput.get_color_by_name(this->myInput.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, &var2);
        }
        else if (var2 == this->myInput.m_input_y104 && menu_edit == MenuEdit::message104) {
            std::string label = this->myInput.m_print_successfully_statement_message_confirm105;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_message_confirm);
            this->myInput.print_statement(label, color_label);
            this->deleting_item();
            //---------------------------------
            menu_edit = MenuEdit::first_opration;
            this->init_input(menu_edit);//save input main
            label = this->myInput.m_print_message_user101;
            color_label = this->myInput.get_color_by_name(this->myInput.m_color_main);
            this->myInput.print_statement(label, color_label, &item);
        }    
        else if (add == this->myInput.m_input_y101 && menu_edit == MenuEdit::message102) {
            std::string label = this->myInput.m_print_successfully_statement_message_confirm101;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_message_confirm);
            this->myInput.print_statement(label, color_label);
            this->set_add();
            //----------------------
            menu_edit = this->menu_exist(MenuEdit::add) ==  "" ? MenuEdit::message102:MenuEdit::add;
            this->init_input(menu_edit);//save input add
            continue;
        }
        else if (search == this->myInput.m_input_y102 && menu_edit == MenuEdit::message101) {
            std::string label = this->myInput.m_print_successfully_statement_message_confirm102;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_message_confirm);
            this->myInput.print_statement(label, color_label);
            this->set_search();
            //-------------------------
            menu_edit = MenuEdit::chose_operation;
            this->init_input(menu_edit);//save input option
            this->menu_exist(MenuEdit::chose_operation);
            label = this->myInput.m_print_message_user102;
            color_label = this->myInput.get_color_by_name(this->myInput.m_color_confirm);
            this->myInput.print_statement(label, color_label, &option);
        }
        else if (var == this->myInput.m_input_y103 && menu_edit == MenuEdit::message103) {
            std::string label = this->myInput.m_print_successfully_statement_message_confirm103;
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_successfully_statement_message_confirm);
            this->myInput.print_statement(label, color_label);
            this->set_edit();
            //--------------------------
            menu_edit = MenuEdit::chose_operation;
            this->init_input(menu_edit);//save input option
            label = this->myInput.m_print_message_user102;
            color_label = this->myInput.get_color_by_name(this->myInput.m_color_confirm);
            this->myInput.print_statement(label, color_label, &option);
        }
        else if (add == this->myInput.m_input_n101 && menu_edit == MenuEdit::message102 || search == this->myInput.m_input_n102 && menu_edit == MenuEdit::message101|| var == this->myInput.m_input_n103 && menu_edit == MenuEdit::message103) {
            this->pop_array();
            //-------------------------------------
            menu_edit = get_key_menu(menu_edit);
            *this->get_input_value(menu_edit) = this->menu_exist(menu_edit);
            menu_edit = *this->get_input_value(menu_edit) != "" ? menu_edit : get_key_menu(menu_edit);
            this->init_input(menu_edit);//save input add or search or edit
            continue;
        }
        else if (add == "" && menu_edit == MenuEdit::message102 || search == "" && menu_edit == MenuEdit::message101 || var == "" && menu_edit == MenuEdit::message103) {
            this->init_input(menu_edit);//save input add or search or edit
            std::vector<Input> v1 = this->myInput.vec;
            std::string label = this->get_m_print_statement_confirm_user(menu_edit);
            v1[0].m_index = menu_edit != MenuEdit::message101 ? this->myInput.m_index : std::to_string(this->myInput.m_id);
            this->myInput.tableResult77(v1, label);
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_statement_confirm);
            this->myInput.print_statement(label, color_label, this->get_input_value(menu_edit));
            }
        else {
            // no save input in error
            std::string label = this->get_m_print_error_statement_confirm(menu_edit);
            int color_label = this->myInput.get_color_by_name(this->myInput.m_color_error_statement_confirm);
            this->myInput.print_statement(label, color_label);
            label = this->get_m_print_statement_confirm_user(menu_edit);
            color_label = this->myInput.get_color_by_name(this->get_m_print_color_confirm_user(menu_edit));
            this->myInput.print_statement(label, color_label, this->get_input_value(menu_edit));
        } 
        // if(){} for empty value option and item and var
    } while (true);
}

bool Calculator::isValidIntegr(int& value, MenuEdit section) {
    do {
        if (std::cin.good() && value > 0 && value <= menu.size()) {
            return false;
        }
        else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        std::string label = this->get_m_print_error_menu_statement(section);
        int color_label = this->myInput.get_color_by_name(this->myInput.m_color_error_menu_statement);
        this->myInput.print_statement(label, color_label);
        label = this->get_m_print_menu_statement(section);
        color_label = this->myInput.get_color_by_name(this->myInput.m_color_menu_statement);
        this->myInput.print_statement(label, color_label, &value);
    } while (true);
}
