class Language: public Section, private InitObject, private ReadFile, public App {
public:
    std::vector<std::vector<Input>> myResult;
    int m_index;
    std::string m_application;
    std::string m_name;
    std::string m_input_help101;
    std::string m_print_help101;
    std::string m_input_help102;
    std::string m_print_help102;
    std::string m_input_help103;
    std::string m_print_help103;
    std::string m_input_help104;
    std::string m_print_help104;
    std::string m_input_help105;
    std::string m_print_help105;
    std::string m_input_help106;
    std::string m_print_help106;
    std::string m_print_successfully_menu_statement_main_screen;
    std::string m_print_successfully_menu_statement_add_screen;
    std::string m_print_successfully_menu_statement_search_screen;
    std::string m_print_successfully_menu_statement_confirm_screen;
    std::string m_print_successfully_menu_statement_edit_screen;
    std::string m_print_successfully_menu_statement_delete_screen;
    std::string m_menu_title101;
    std::string m_input_menu101;
    std::string m_print_menu_statement101;
    std::string m_print_error_menu_statement101;
    std::string m_print_successfully_menu_statement101;
    std::string m_print_screen101;
    std::string m_menu_title102;
    std::string m_input_menu102;
    std::string m_print_menu_statement102;
    std::string m_print_error_menu_statement102;
    std::string m_print_successfully_menu_statement102;
    std::string m_print_screen102;
    std::string m_menu_title103;
    std::string m_input_menu103;
    std::string m_print_menu_statement103;
    std::string m_print_error_menu_statement103;
    std::string m_print_successfully_menu_statement103;
    std::string m_print_screen103;
    std::string m_menu_title104;
    std::string m_input_menu104;
    std::string m_print_menu_statement104;
    std::string m_print_error_menu_statement104;
    std::string m_print_successfully_menu_statement104;
    std::string m_print_screen104;
    std::string m_menu_title105;
    std::string m_input_menu105;
    std::string m_print_menu_statement105;
    std::string m_print_error_menu_statement105;
    std::string m_print_successfully_menu_statement105;
    std::string m_print_screen105;
    std::string m_menu_title106;
    std::string m_input_menu106;
    std::string m_print_menu_statement106;
    std::string m_print_error_menu_statement106;
    std::string m_print_successfully_menu_statement106;
    std::string m_print_screen106;
    std::string m_print_screen107;
    std::string m_print_statement_confirm101;
    std::string m_print_error_statement_confirm101;
    std::string m_print_successfully_statement_message_confirm101;
    std::string m_print_number101;
    std::string m_print_error_number101;
    std::string m_print_operator101;
    std::string m_print_error_operator101;
    std::string m_input_clear101;
    std::string m_print_clear101;
    std::string m_input_y101;
    std::string m_input_n101;
    std::string m_input_result_table101;
    std::string m_print_statement_confirm102;
    std::string m_print_error_statement_confirm102;
    std::string m_print_successfully_statement_message_confirm102;
    std::string m_print_number102;
    std::string m_print_error_number102;
    std::string m_print_operator102;
    std::string m_print_error_operator102;
    std::string m_input_clear102;
    std::string m_print_clear102;
    std::string m_input_y102;
    std::string m_input_n102;
    std::string m_input_result_table102;
    std::string m_print_statement_confirm103;
    std::string m_print_error_statement_confirm103;
    std::string m_print_successfully_statement_message_confirm103;
    std::string m_print_number103;
    std::string m_print_error_number103;
    std::string m_print_operator103;
    std::string m_print_error_operator103;
    std::string m_input_clear103;
    std::string m_print_clear103;
    std::string m_input_y103;
    std::string m_input_n103;
    std::string m_input_result_table103;
    std::string m_input_key101;
    std::string m_input_key102;
    std::string m_print_successfully_statement_confirm101;
    std::string m_print_successfully_statement_confirm102;
    std::string m_print_message_user101;
    std::string m_print_error_message_user101;
    std::string m_print_successfully_statement_message_confirm104;
    std::string m_input_key103;
    std::string m_input_key104;
    std::string m_print_successfully_statement_confirm103;
    std::string m_print_successfully_statement_confirm104;
    std::string m_print_message_user102;
    std::string m_print_error_message_user102;
    std::string m_input_y104;
    std::string m_input_n104;
    std::string m_print_message_user103;
    std::string m_print_error_message_user103;
    std::string m_print_successfully_statement_message_confirm105;
    std::string m_data_title;
    std::string m_result_title;
    std::string m_result_table_suggestion;
    std::string m_value;
    std::string m_mark;
    std::string m_total;
    std::string m_address;
    std::string m_app;
    std::string m_app_address;
    std::string m_heddin_result;
    std::string m_heddin_result_address;
    std::string m_result_fill;
    int m_result_space;
    std::string m_heddin_sugges_result;
    std::string m_heddin_sugges_address;
    std::string m_sugges_fill;
    int m_sugges_space;
    std::string m_heddin_data_result;
    std::string m_heddin_data_address;
    std::string m_data_fill;
    int m_data_space;
    std::string m_interrogative;
    std::string m_value_result;
    int m_menu_space;
    std::string m_heddin_menu_address;
    std::string m_type_table_operator;
    bool m_center_label;
    std::string m_color_help;
    std::string m_color_result_title;
    std::string m_color_menu_statement;
    std::string m_color_error_menu_statement;
    std::string m_color_successfully_menu_statement;
    std::string m_color_statement_confirm;
    std::string m_color_error_statement_confirm;
    std::string m_color_successfully_statement_confirm;
    std::string m_color_successfully_statement_message_confirm;
    std::string m_color_number;
    std::string m_color_error_number;
    std::string m_color_operator;
    std::string m_color_error_operator;
    std::string m_color_clear;
    std::string m_color_select;
    std::string m_color_result_table;
    std::string m_color_sugges_table;
    std::string m_color_sugges_title;
    std::string m_color_data_table;
    std::string m_color_data_title;
    std::string m_color_menu_title;
    std::string m_color_menu_table;
    std::string m_color_error_message_user;
    Language(){
        this->json = this->m_read_setting();
        this->read_setting();
        std::vector<std::string> names = { "addition", "search", "edit" };
        const int size = 3;
        AddSearchEdit add_search_edit[size];
        for (int i = 0; i < names.size(); i++)
            add_search_edit[i] = this->m_read_add_search_edit(names[i]);
        add = add_search_edit[0];
        this->read_add();
        search = add_search_edit[1];
        this->read_search();
        edit = add_search_edit[2];
        this->read_edit();
        the_result = this->m_read_result();
        this->read_result();
        table = this->m_read_table();
        this->read_table();
        color = this->m_read_colors();
        this->read_colors();
        main = this->m_read_main();
        this->read_main();
        dialog = this->m_read_dialog();
        this->read_dialog();
        help = this->m_read_help();
        this->read_help();
        confirm = this->m_read_confirm();
        this->read_confirm();
        m_delete = this->m_read_delete();
        this->read_delete();
    }
    std::string get_m_print_number(InputValid input_value);
    std::string get_m_print_operator(InputValid input_value);
    std::string get_m_print_error_number(InputValid input_value);
    std::string get_m_print_error_operator(InputValid input_value);
    std::string get_m_input_clear(InputValid input_value);
    std::string get_m_print_clear(InputValid input_value);
    std::string get_m_input_result_table(InputValid input_value);
    std::string get_m_input_menu(InputValid input_value);
    std::string get_m_input_menu(MenuEdit menu_edit);
    std::string get_m_print_successfully_menu_statement(MenuEdit menu_edit);
    std::string get_m_input_help(InputValid input_value);
    std::string get_m_input_help(MenuEdit menu_edit);
    std::string get_m_print_help(InputValid input_value);
    std::string get_m_print_help(MenuEdit menu_edit);
    std::string get_m_menu_title(MenuEdit menu_edit);
    std::string get_m_print_menu_statement(MenuEdit menu_edit);
    std::string get_m_print_error_menu_statement(MenuEdit menu_edit);
    std::string get_m_print_menu_statement_screen(std::string id);
    std::string get_id_menu(MenuEdit menu_edit);
    std::string get_m_print_message_user(MenuEdit menu_edit);
    std::string get_m_input_y(MenuEdit menu_edit);
    std::string get_m_input_n(MenuEdit menu_edit);
    std::string get_m_print_statement_confirm(MenuEdit menu_edit);
    std::string get_m_print_error_statement_confirm(MenuEdit menu_edit);
    std::string get_m_print_successfully_statement_confirm(Section::InputKey input_key);
    Section::InputKey get_section(std::string input_key, std::string add, std::string search, std::string var);
    Section::MenuEdit get_menu_edit(std::string menu, Section::MenuEdit menu_edit);

private:
    void read_help()override;
    void read_dialog()override;
    void read_add()override;
    void read_search()override;
    void read_edit()override;
    void read_delete()override;
    void read_confirm()override;
    void read_main()override;
    void read_table()override;
    void read_colors()override;
    void read_setting()override;
    void read_result()override;
};


void Language::read_help() {
    this->m_input_help101 = help.m_input_help_add;
    this->m_print_help101 = help.m_print_help_add;
    this->m_input_help102 = help.m_input_help_search;
    this->m_print_help102 = help.m_print_help_search;
    this->m_input_help103 = help.m_input_help_edit;
    this->m_print_help103 = help.m_print_help_edit;

    this->m_input_help104 = help.m_input_help_main;
    this->m_print_help104 = help.m_print_help_main;

    this->m_input_help105 = help.m_input_help_confirm;
    this->m_print_help105 = help.m_print_help_confirm;

    this->m_input_help106 = help.m_input_help_delete;
    this->m_print_help106 = help.m_print_help_delete;

}
void Language::read_dialog() {
    this->m_print_successfully_menu_statement_main_screen = dialog.m_print_successfully_menu_statement_main_screen;
    this->m_print_successfully_menu_statement_add_screen = dialog.m_print_successfully_menu_statement_add_screen;
    this->m_print_successfully_menu_statement_search_screen = dialog.m_print_successfully_menu_statement_search_screen;
    this->m_print_successfully_menu_statement_confirm_screen = dialog.m_print_successfully_menu_statement_confirm_screen;
    this->m_print_successfully_menu_statement_edit_screen = dialog.m_print_successfully_menu_statement_edit_screen;
    this->m_print_successfully_menu_statement_delete_screen = dialog.m_print_successfully_menu_statement_delete_screen;
    //add
    this->m_menu_title101 = dialog.m_menu_title_add;
    this->m_input_menu101 = dialog.m_input_menu_add;
    this->m_print_menu_statement101 = dialog.m_print_menu_statement_add;
    this->m_print_error_menu_statement101 = dialog.m_print_error_menu_statement_add;
    this->m_print_successfully_menu_statement101 = dialog.m_print_successfully_menu_statement_add;


    this->m_print_screen101 = dialog.m_print_screen_add;
    //search
    this->m_menu_title102 = dialog.m_menu_title_search;
    this->m_input_menu102 = dialog.m_input_menu_search;
    this->m_print_menu_statement102 = dialog.m_print_menu_statement_search;
    this->m_print_error_menu_statement102 = dialog.m_print_error_menu_statement_search;
    this->m_print_successfully_menu_statement102 = dialog.m_print_successfully_menu_statement_search;


    this->m_print_screen102 = dialog.m_print_screen_search;
    //edit
    this->m_menu_title103 = dialog.m_menu_title_edit;
    this->m_input_menu103 = dialog.m_input_menu_edit;
    this->m_print_menu_statement103 = dialog.m_print_menu_statement_edit;
    this->m_print_error_menu_statement103 = dialog.m_print_error_menu_statement_edit;
    this->m_print_successfully_menu_statement103 = dialog.m_print_successfully_menu_statement_edit;


    this->m_print_screen103 = dialog.m_print_screen_edit;
    //main
    this->m_menu_title104 = dialog.m_menu_title_main;
    this->m_input_menu104 = dialog.m_input_menu_main;
    this->m_print_menu_statement104 = dialog.m_print_menu_statement_main;
    this->m_print_error_menu_statement104 = dialog.m_print_error_menu_statement_main;
    this->m_print_successfully_menu_statement104 = dialog.m_print_successfully_menu_statement_main;


    this->m_print_screen104 = dialog.m_print_screen_main;
    //confirm
    this->m_menu_title105 = dialog.m_menu_title_confirm;
    this->m_input_menu105 = dialog.m_input_menu_confirm;
    this->m_print_menu_statement105 = dialog.m_print_menu_statement_confirm;
    this->m_print_error_menu_statement105 = dialog.m_print_error_menu_statement_confirm;
    this->m_print_successfully_menu_statement105 = dialog.m_print_successfully_menu_statement_confirm;


    this->m_print_screen105 = dialog.m_print_screen_confirm;

    //delete
    this->m_menu_title106 = dialog.m_menu_title_delete;
    this->m_input_menu106 = dialog.m_input_menu_delete;
    this->m_print_menu_statement106 = dialog.m_print_menu_statement_delete;
    this->m_print_error_menu_statement106 = dialog.m_print_error_menu_statement_delete;
    this->m_print_successfully_menu_statement106 = dialog.m_print_successfully_menu_statement_delete;
    this->m_print_screen106 = dialog.m_print_screen_delete;
    //exit
    this->m_print_screen107 = dialog.m_print_screen_exit;

}
void Language::read_add() {
    this->m_print_statement_confirm101 = add.m_print_statement_confirm;
    this->m_print_error_statement_confirm101 = add.m_print_error_statement_confirm;
    this->m_print_successfully_statement_message_confirm101 = add.m_print_successfully_statement_message_confirm;

    this->m_print_number101 = add.m_print_number;
    this->m_print_error_number101 = add.m_print_error_number;

    this->m_print_operator101 = add.m_print_operator;
    this->m_print_error_operator101 = add.m_print_error_operator;


    this->m_input_clear101 = add.m_input_clear;
    this->m_print_clear101 = add.m_print_clear;

    this->m_input_y101 = add.m_input_y;
    this->m_input_n101 = add.m_input_n;
    this->m_input_result_table101 = add.m_input_result_table;

}
void Language::read_search() {
    this->m_print_statement_confirm102 = search.m_print_statement_confirm;
    this->m_print_error_statement_confirm102 = search.m_print_error_statement_confirm;
    this->m_print_successfully_statement_message_confirm102 = search.m_print_successfully_statement_message_confirm;

    this->m_print_number102 = search.m_print_number;
    this->m_print_error_number102 = search.m_print_error_number;
    this->m_print_operator102 = search.m_print_operator;
    this->m_print_error_operator102 = search.m_print_error_operator;

    this->m_input_clear102 = search.m_input_clear;
    this->m_print_clear102 = search.m_print_clear;

    this->m_input_y102 = search.m_input_y;
    this->m_input_n102 = search.m_input_n;
    this->m_input_result_table102 = search.m_input_result_table;

}
void Language::read_edit() {
    this->m_print_statement_confirm103 = edit.m_print_statement_confirm;
    this->m_print_error_statement_confirm103 = edit.m_print_error_statement_confirm;
    this->m_print_successfully_statement_message_confirm103 = edit.m_print_successfully_statement_message_confirm;

    this->m_print_number103 = edit.m_print_number;
    this->m_print_error_number103 = edit.m_print_error_number;
    this->m_print_operator103 = edit.m_print_operator;
    this->m_print_error_operator103 = edit.m_print_error_operator;

    this->m_input_clear103 = edit.m_input_clear;
    this->m_print_clear103 = edit.m_print_clear;

    this->m_input_y103 = edit.m_input_y;
    this->m_input_n103 = edit.m_input_n;
    this->m_input_result_table103 = edit.m_input_result_table;

}
void Language::read_delete() {
    this->m_input_y104 = m_delete.m_input_y;
    this->m_input_n104 = m_delete.m_input_n;
    this->m_print_message_user103 = m_delete.m_print_message_user;
    this->m_print_error_message_user103 = m_delete.m_print_error_message_user;
    this->m_print_successfully_statement_message_confirm105 = m_delete.m_print_successfully_statement_message_confirm;

}
void Language::read_confirm() {
    this->m_input_key103 = confirm.m_input_key_edit;
    this->m_input_key104 = confirm.m_input_key_delete;
    this->m_print_successfully_statement_confirm103 = confirm.m_print_successfully_statement_confirm_edit;
    this->m_print_successfully_statement_confirm104 = confirm.m_print_successfully_statement_confirm_delete;
    this->m_print_message_user102 = confirm.m_print_message_user;
    this->m_print_error_message_user102 = confirm.m_print_error_message_user;

}
void Language::read_main() {
    this->m_input_key101 = main.m_input_key_add;
    this->m_input_key102 = main.m_input_key_search;
    this->m_print_successfully_statement_confirm101 = main.m_print_successfully_statement_confirm_add;
    this->m_print_successfully_statement_confirm102 = main.m_print_successfully_statement_confirm_search;

    this->m_print_message_user101 = main.m_print_message_user;
    this->m_print_error_message_user101 = main.m_print_error_message_user;
    this->m_print_successfully_statement_message_confirm104 = main.m_print_successfully_statement_message_confirm;

}
void Language::read_table() {
    this->m_data_title = table.m_data_title;
    this->m_result_title = table.m_result_title;
    this->m_result_table_suggestion = table.m_result_table_suggestion;

    this->m_value = table.m_value;
    this->m_mark = table.m_mark;
    this->m_total = table.m_total;
    this->m_address = table.m_address;
    this->m_app = table.m_app;
    this->m_app_address = table.m_app_address;


    this->m_heddin_result = table.m_heddin_result;
    this->m_heddin_result_address = table.m_heddin_result_address;
    this->m_result_fill = table.m_result_fill;
    this->m_result_space = table.m_result_space;

    this->m_heddin_sugges_result = table.m_heddin_sugges_result;
    this->m_heddin_sugges_address = table.m_heddin_sugges_address;
    this->m_sugges_fill = table.m_sugges_fill;
    this->m_sugges_space = table.m_sugges_space;

    this->m_heddin_data_result = table.m_heddin_data_result;
    this->m_heddin_data_address = table.m_heddin_data_address;
    this->m_data_space = table.m_data_space;
    this->m_interrogative = table.m_interrogative;
    this->m_value_result = table.m_value_result;
    this->m_menu_space = table.m_menu_space;
    this->m_heddin_menu_address = table.m_heddin_menu_address;
    this->m_type_table_operator = table.m_type_table_operator;
    this->m_center_label = table.m_center_label;

}
void Language::read_colors() {
    this->m_color_help = color.m_color_help;
    this->m_color_result_title = color.m_color_result_title;
    this->m_color_menu_statement = color.m_color_menu_statement;
    this->m_color_error_menu_statement = color.m_color_error_menu_statement;
    this->m_color_successfully_menu_statement = color.m_color_successfully_menu_statement;
    this->m_color_statement_confirm = color.m_color_statement_confirm;
    this->m_color_error_statement_confirm = color.m_color_error_statement_confirm;
    this->m_color_successfully_statement_confirm = color.m_color_successfully_statement_confirm;
    this->m_color_successfully_statement_message_confirm = color.m_color_successfully_statement_message_confirm;
    this->m_color_number = color.m_color_number;
    this->m_color_error_number = color.m_color_error_number;
    this->m_color_operator = color.m_color_operator;
    this->m_color_error_operator = color.m_color_error_operator;
    this->m_color_clear = color.m_color_clear;
    this->m_color_select = color.m_color_select;
    this->m_color_result_table = color.m_color_result_table;
    this->m_color_sugges_table = color.m_color_sugges_table;
    this->m_color_sugges_title = color.m_color_sugges_title;
    this->m_color_data_table = color.m_color_data_table;
    this->m_color_data_title = color.m_color_data_title;
    this->m_color_menu_title = color.m_color_menu_title;
    this->m_color_menu_table = color.m_color_menu_table;
    this->m_color_error_message_user = color.m_color_error_message_user;

}
void Language::read_setting() {
    this->m_index = json.m_index;
    this->m_application = json.m_application;
    this->m_name = json.m_name;

}
void Language::read_result() {
    this->myResult = the_result;
}


Section::InputKey Language::get_section(std::string input_key, std::string add, std::string search, std::string var) {

    if (input_key == this->m_input_key101 && add == "nero-soft")
        return Section::InputKey::first_call_add;
    else if (input_key == this->m_input_key102 && search == "nero-soft")
        return Section::InputKey::first_call_search;
    else if (input_key == this->m_input_key103 && var == "nero-soft")
        return Section::InputKey::first_call_edit;
    else if (input_key == this->m_input_key101)
        return Section::InputKey::addition;
    else if (input_key == this->m_input_key102)
        return Section::InputKey::search;
    else if (input_key == this->m_input_key103)
        return Section::InputKey::edit;
    else if (input_key == this->m_input_key104)
        return Section::InputKey::deletion;
}
Section::MenuEdit Language::get_menu_edit(std::string menu, Section::MenuEdit menu_edit) {
    if (menu == this->m_print_screen101)
        return menu_edit != Section::MenuEdit::add ? Section::MenuEdit::message102 : Section::MenuEdit::add;
    else if (menu == this->m_print_screen102)
        return  menu_edit != Section::MenuEdit::search ? Section::MenuEdit::message101 : Section::MenuEdit::search;
    else if (menu == this->m_print_screen103)
        return menu_edit != Section::MenuEdit::update_item ? Section::MenuEdit::message103 : Section::MenuEdit::update_item;
    else if (menu == this->m_print_screen104)
        return Section::MenuEdit::first_opration;
    else if (menu == this->m_print_screen105)
        return Section::MenuEdit::chose_operation;
    else if (menu == this->m_print_screen106)
        return Section::MenuEdit::message104;
}
std::string Language::get_m_print_number(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_number101;
    case InputValid::input_mark_search:
        return this->m_print_number102;
    case InputValid::input_mark_update_add:
        return this->m_print_number103;
    }
}
std::string  Language::get_m_print_operator(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_operator101;
    case InputValid::input_mark_search:
        return this->m_print_operator102;
    case InputValid::input_mark_update_add:
        return this->m_print_operator103;
    }
}
std::string Language::get_m_print_error_number(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_error_number101;
    case InputValid::input_mark_search:
        return this->m_print_error_number102;
    case InputValid::input_mark_update_add:
        return this->m_print_error_number103;
    }
}
std::string Language::get_m_print_error_operator(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_error_operator101;
    case InputValid::input_mark_search:
        return this->m_print_error_operator102;
    case InputValid::input_mark_update_add:
        return this->m_print_error_operator103;
    }
}
std::string Language::get_m_input_clear(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_input_clear101;
    case InputValid::input_mark_search:
        return this->m_input_clear102;
    case InputValid::input_mark_update_add:
        return this->m_input_clear103;
    }
}
std::string Language::get_m_print_clear(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_clear101;
    case InputValid::input_mark_search:
        return this->m_print_clear102;
    case InputValid::input_mark_update_add:
        return this->m_print_clear103;
    }
}
std::string Language::get_m_input_result_table(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_input_result_table101;
    case InputValid::input_mark_search:
        return this->m_input_result_table102;
    case InputValid::input_mark_update_add:
        return this->m_input_result_table103;
    }
}
std::string Language::get_m_input_menu(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_input_menu101;
    case InputValid::input_mark_search:
        return this->m_input_menu102;
    case InputValid::input_mark_update_add:
        return this->m_input_menu103;
    }
}
std::string Language::get_m_input_menu(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::message102:
    case Section::MenuEdit::add:
        return this->m_input_menu101;

    case Section::MenuEdit::message101:
    case Section::MenuEdit::search:
        return this->m_input_menu102;

    case Section::MenuEdit::message103:
    case Section::MenuEdit::update_item:
        return this->m_input_menu103;

    case Section::MenuEdit::first_opration:
        return this->m_input_menu104;

    case Section::MenuEdit::message104:
        return this->m_input_menu106;

    case Section::MenuEdit::chose_operation:
        return this->m_input_menu105;
    }
}
std::string Language::get_m_print_successfully_menu_statement(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::message102:
    case Section::MenuEdit::add:
        return this->m_print_successfully_menu_statement101;

    case Section::MenuEdit::message101:
    case Section::MenuEdit::search:
        return this->m_print_successfully_menu_statement102;

    case Section::MenuEdit::message103:
    case Section::MenuEdit::update_item:
        return this->m_print_successfully_menu_statement103;

    case Section::MenuEdit::first_opration:
        return this->m_print_successfully_menu_statement104;

    case Section::MenuEdit::message104:
        return this->m_print_successfully_menu_statement106;

    case Section::MenuEdit::chose_operation:
        return this->m_print_successfully_menu_statement105;
    }
}
std::string Language::get_m_input_help(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_input_help101;
    case InputValid::input_mark_search:
        return this->m_input_help102;
    case InputValid::input_mark_update_add:
        return this->m_input_help103;
    }
}
std::string Language::get_m_input_help(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::first_opration:
        return this->m_input_help104;
    case MenuEdit::chose_operation:
        return this->m_input_help105;
    case MenuEdit::message104:
        return this->m_input_help106;
    default:
        return "";
    }
}
std::string Language::get_m_print_help(InputValid input_value) {
    switch (input_value)
    {
    case InputValid::addition:
        return this->m_print_help101;
    case InputValid::input_mark_search:
        return this->m_print_help102;
    case InputValid::input_mark_update_add:
        return this->m_print_help103;
    }
}
std::string Language::get_m_print_help(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::first_opration:
        return this->m_print_help104;
    case MenuEdit::chose_operation:
        return this->m_print_help105;
    case MenuEdit::message104:
        return this->m_print_help106;
    }
}
std::string Language::get_m_menu_title(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::message102:
    case MenuEdit::add:
        return this->m_menu_title101;
    case MenuEdit::message101:
    case MenuEdit::search:
        return this->m_menu_title102;
    case MenuEdit::message103:
    case MenuEdit::update_item:
        return this->m_menu_title103;
    case MenuEdit::first_opration:
        return this->m_menu_title104;
    case MenuEdit::chose_operation:
        return this->m_menu_title105;
    case MenuEdit::message104:
        return this->m_menu_title106;
    }
}
std::string Language::get_m_print_menu_statement(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::message102:
    case MenuEdit::add:
        return this->m_print_menu_statement101;
    case MenuEdit::message101:
    case MenuEdit::search:
        return this->m_print_menu_statement102;
    case MenuEdit::message103:
    case MenuEdit::update_item:
        return this->m_print_menu_statement103;
    case MenuEdit::first_opration:
        return this->m_print_menu_statement104;
    case MenuEdit::chose_operation:
        return this->m_print_menu_statement105;
    case MenuEdit::message104:
        return this->m_print_menu_statement106;
    }
}
std::string Language::get_m_print_error_menu_statement(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::message102:
    case MenuEdit::add:
        return this->m_print_error_menu_statement101;
    case MenuEdit::message101:
    case MenuEdit::search:
        return this->m_print_error_menu_statement102;
    case MenuEdit::message103:
    case MenuEdit::update_item:
        return this->m_print_error_menu_statement103;
    case MenuEdit::first_opration:
        return this->m_print_error_menu_statement104;
    case MenuEdit::chose_operation:
        return this->m_print_error_menu_statement105;
    case MenuEdit::message104:
        return this->m_print_error_menu_statement106;
    }
}
std::string Language::get_m_print_menu_statement_screen(std::string id) {

    if (id == "menu_search")
        return m_print_successfully_menu_statement_search_screen;
    else if (id == "menu_add")
        return m_print_successfully_menu_statement_add_screen;
    else if (id == "menu_delete")
        return m_print_successfully_menu_statement_delete_screen;
    else if (id == "menu_select")
        return m_print_successfully_menu_statement_main_screen;
    else if (id == "menu_option")
        return m_print_successfully_menu_statement_confirm_screen;
    else if (id == "menu_update")
        return m_print_successfully_menu_statement_edit_screen;

}
std::string Language::get_id_menu(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case MenuEdit::message102:
    case MenuEdit::add:
        return "menu_add";
    case MenuEdit::message101:
    case MenuEdit::search:
        return "menu_search";
    case MenuEdit::message103:
    case MenuEdit::update_item:
        return "menu_update";
    case MenuEdit::first_opration:
        return "menu_select";
    case MenuEdit::message104:
        return "menu_delete";
    case MenuEdit::chose_operation:
        return "menu_option";
    default:
        break;
    }
}
std::string Language::get_m_print_message_user(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::first_opration:
        return m_print_message_user101;
    case Section::MenuEdit::message104:
        return m_print_message_user103;
    case Section::MenuEdit::chose_operation:
        return m_print_message_user102;
    }
}
std::string Language::get_m_input_y(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::message102:
        return this->m_input_y101;
    case Section::MenuEdit::message101:
        return this->m_input_y102;
    case Section::MenuEdit::message103:
        return this->m_input_y103;
    case Section::MenuEdit::message104:
        return this->m_input_y104;
    default:
        return "";
    }
}
std::string Language::get_m_input_n(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::message102:
        return this->m_input_n101;
    case Section::MenuEdit::message101:
        return this->m_input_n102;
    case Section::MenuEdit::message103:
        return this->m_input_n103;
    case Section::MenuEdit::message104:
        return this->m_input_n104;
    default:
        return "";
    }
}
std::string Language::get_m_print_statement_confirm(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::add:
    case Section::MenuEdit::message102:
        return m_print_statement_confirm101;

    case Section::MenuEdit::search:
    case Section::MenuEdit::message101:
        return m_print_statement_confirm102;

    case Section::MenuEdit::update_item:
    case Section::MenuEdit::message103:
        return m_print_statement_confirm103;

    case Section::MenuEdit::first_opration:
        return m_print_message_user101;

    case Section::MenuEdit::message104:
        return m_print_message_user103;

    case Section::MenuEdit::chose_operation:
        return m_print_message_user102;
    }
}
std::string Language::get_m_print_error_statement_confirm(MenuEdit menu_edit) {
    switch (menu_edit)
    {
    case Section::MenuEdit::add:
    case Section::MenuEdit::message102:
        return m_print_error_statement_confirm101;

    case Section::MenuEdit::search:
    case Section::MenuEdit::message101:
        return m_print_error_statement_confirm102;

    case Section::MenuEdit::update_item:
    case Section::MenuEdit::message103:
        return m_print_error_statement_confirm103;

    case Section::MenuEdit::first_opration:
        return m_print_error_message_user101;

    case Section::MenuEdit::message104:
        return m_print_error_message_user103;

    case Section::MenuEdit::chose_operation:
        return m_print_error_message_user102;
    }
}
std::string Language::get_m_print_successfully_statement_confirm(Section::InputKey input_key) {
    switch (input_key)
    {
    case Section::InputKey::addition:
        return this->m_print_successfully_statement_confirm101;
    case Section::InputKey::search:
        return this->m_print_successfully_statement_confirm102;
    case Section::InputKey::edit:
        return this->m_print_successfully_statement_confirm103;
    case Section::InputKey::deletion:
        return this->m_print_successfully_statement_confirm104;
    case Section::InputKey::first_call_add:
        return this->m_print_successfully_statement_confirm101;
    case Section::InputKey::first_call_search:
        return this->m_print_successfully_statement_confirm102;
    case Section::InputKey::first_call_edit:
        return this->m_print_successfully_statement_confirm103;
    }
}




