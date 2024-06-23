class Language: public Section, private InitObject, private ReadFile, public App {
public:
    std::vector<std::vector<Input>> myResult;
    int m_index;
    std::string m_application;
    std::string m_name;
    std::string m_language;
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
    std::string m_print_successfully_statement_confirm105;
    std::string m_print_message_user102;
    std::string m_print_error_message_user102;
    std::string m_input_y104;
    std::string m_input_n104;
    std::string m_print_statement_confirm104;
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
    std::string m_color_value_result;
    std::string m_color_operator_result;
    std::string m_color_total_result;
    std::string m_color_address_result;
    std::string m_color_value_sugges;
    std::string m_color_operator_sugges;
    std::string m_color_total_sugges;
    std::string m_color_address_sugges;
    std::string m_line_result;
    std::string m_dismiss_line_result;
    std::string m_dismiss_word_result;
    std::string m_line_sugges;
    std::string m_dismiss_line_sugges;
    std::string m_dismiss_word_sugges;
    std::string m_color_value_data;
    std::string m_color_operator_data;
    std::string m_color_total_data;
    std::string m_color_address_data;
    std::string m_line_data;
    std::string m_dismiss_line_data;
    std::string m_dismiss_word_data;

    std::string m_color_app_menu;
    std::string m_color_address_menu;
    std::string m_color_app_exit_menu;
    std::string m_color_app_main_menu;
    std::string m_color_app_add_menu;
    std::string m_color_app_search;
    std::string m_color_app_confirm_menu;
    std::string m_color_app_edit_menu;
    std::string m_color_app_delete_menu;

    std::string m_line_menu;
    std::string m_dismiss_line_menu;
    std::string m_dismiss_word_menu;

    std::string m_print_successfuly_select_item101;
    std::string m_print_successfuly_select_item102;
    std::string m_print_successfuly_select_item103;

    std::string m_input_search101;
    std::string m_input_search102;
    std::string m_input_search103;
    std::string m_input_result101;
    std::string m_input_result102;
    std::string m_input_result103;

    std::string m_heddin_table;

    std::string m_color_main;
    std::string m_color_confirm;



    std::string m_color_confirm_table;
    std::string m_color_confirm_title;
    std::string m_color_value_confirm;
    std::string m_color_operator_confirm;
    std::string m_color_total_confirm;
    std::string m_color_address_confirm;

    std::string m_confirm_title;
    std::string m_value_confirm_result;
    int m_confirm_space;
    std::string m_line_confirm;
    std::string m_dismiss_word_confirm;
    std::string m_dismiss_line_confirm;
    std::string m_heddin_confirm_result;
    std::string m_heddin_confirm_address;



    std::string m_color_delete_table;
    std::string m_color_delete_title;
    std::string m_color_value_delete;
    std::string m_color_operator_delete;
    std::string m_color_total_delete;
    std::string m_color_address_delete;

    std::string m_delete_title;
    int m_delete_space;
    std::string m_line_delete;
    std::string m_dismiss_word_delete;
    std::string m_dismiss_line_delete;
    std::string m_heddin_delete_result;
    std::string m_heddin_delete_address;



    std::string m_color_display_table;
    std::string m_color_display_title;
    std::string m_color_value_display;
    std::string m_color_operator_display;
    std::string m_color_total_display;
    std::string m_color_address_display;

    std::string m_display_title;
    int m_display_space;
    std::string m_line_display;
    std::string m_dismiss_word_display;
    std::string m_dismiss_line_display;
    std::string m_heddin_display_result;
    std::string m_heddin_display_address;


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

    this->m_print_successfuly_select_item101 = add.m_print_successfuly_select_item;

    this->m_input_search101 = add.m_input_search;
    this->m_input_result101 = add.m_input_result;
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
    this->m_print_successfuly_select_item102 = search.m_print_successfuly_select_item;

    this->m_input_search102 = search.m_input_search;
    this->m_input_result102 = search.m_input_result;
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
    this->m_print_successfuly_select_item103 = edit.m_print_successfuly_select_item;

    this->m_input_search103 = edit.m_input_search;
    this->m_input_result103 = edit.m_input_result;
}
void Language::read_delete() {
    this->m_input_y104 = m_delete.m_input_y;
    this->m_input_n104 = m_delete.m_input_n;
    this->m_print_statement_confirm104 = m_delete.m_print_statement_confirm;
    this->m_print_error_message_user103 = m_delete.m_print_error_message_user;
    this->m_print_successfully_statement_message_confirm105 = m_delete.m_print_successfully_statement_message_confirm;
    this->m_print_successfully_statement_confirm105 = m_delete.m_print_successfully_statement_confirm_delete;

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

    this->m_line_result = table.m_line_result;
    this->m_dismiss_line_result = table.m_dismiss_line_result;
    this->m_dismiss_word_result = table.m_dismiss_word_result;

    this->m_line_sugges = table.m_line_sugges;
    this->m_dismiss_line_sugges = table.m_dismiss_line_sugges;
    this->m_dismiss_word_sugges = table.m_dismiss_word_sugges;

    this->m_line_data = table.m_line_data;
    this->m_dismiss_line_data = table.m_dismiss_line_data;
    this->m_dismiss_word_data = table.m_dismiss_word_data;

    this->m_line_menu = table.m_line_menu;
    this->m_dismiss_line_menu = table.m_dismiss_line_menu;
    this->m_dismiss_word_menu = table.m_dismiss_word_menu;

    this->m_heddin_table = table.m_heddin_table;

    this->m_confirm_title = table.m_confirm_title;
    this->m_value_confirm_result = table.m_value_confirm_result;
    this->m_confirm_space = table.m_confirm_space;
    this->m_line_confirm = table.m_line_confirm;
    this->m_dismiss_word_confirm = table.m_dismiss_word_confirm;
    this->m_dismiss_line_confirm = table.m_dismiss_line_confirm;
    this->m_heddin_confirm_result = table.m_heddin_confirm_result;
    this->m_heddin_confirm_address = table.m_heddin_confirm_address;


    this->m_delete_title = table.m_delete_title;
    this->m_delete_space = table.m_delete_space;
    this->m_line_delete = table.m_line_delete;
    this->m_dismiss_word_delete = table.m_dismiss_word_delete;
    this->m_dismiss_line_delete = table.m_dismiss_line_delete;
    this->m_heddin_delete_result = table.m_heddin_delete_result;
    this->m_heddin_delete_address = table.m_heddin_delete_address;

    this->m_display_title = table.m_display_title;
    this->m_display_space = table.m_display_space;
    this->m_line_display = table.m_line_display;
    this->m_dismiss_word_display = table.m_dismiss_word_display;
    this->m_dismiss_line_display = table.m_dismiss_line_display;
    this->m_heddin_display_result = table.m_heddin_display_result;
    this->m_heddin_display_address = table.m_heddin_display_address;
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
    this->m_color_value_result = color.m_color_value_result;
    this->m_color_operator_result = color.m_color_operator_result;
    this->m_color_total_result = color.m_color_total_result;
    this->m_color_address_result = color.m_color_address_result;
    this->m_color_value_sugges = color.m_color_value_sugges;
    this->m_color_operator_sugges = color.m_color_operator_sugges;
    this->m_color_total_sugges = color.m_color_total_sugges;
    this->m_color_address_sugges = color.m_color_address_sugges;
    
    this->m_color_value_data = color.m_color_value_data;
    this->m_color_operator_data = color.m_color_operator_data;
    this->m_color_total_data = color.m_color_total_data;
    this->m_color_address_data = color.m_color_address_data;


    this->m_color_app_menu = color.m_color_app_menu;
    this->m_color_address_menu = color.m_color_address_menu;
    this->m_color_app_exit_menu = color.m_color_app_exit_menu;
    this->m_color_app_main_menu = color.m_color_app_main_menu;
    this->m_color_app_add_menu = color.m_color_app_add_menu;
    this->m_color_app_search = color.m_color_app_search;
    this->m_color_app_confirm_menu = color.m_color_app_confirm_menu;
    this->m_color_app_edit_menu = color.m_color_app_edit_menu;
    this->m_color_app_delete_menu = color.m_color_app_delete_menu;

    this->m_color_main = color.m_color_main;
    this->m_color_confirm = color.m_color_confirm;

    this->m_color_confirm_table = color.m_color_confirm_table;
    this->m_color_confirm_title = color.m_color_confirm_title;
    this->m_color_value_confirm = color.m_color_value_confirm;
    this->m_color_operator_confirm = color.m_color_operator_confirm;
    this->m_color_total_confirm = color.m_color_total_confirm;
    this->m_color_address_confirm = color.m_color_address_confirm;


    this->m_color_delete_table = color.m_color_delete_table;
    this->m_color_delete_title = color.m_color_delete_title;
    this->m_color_value_delete = color.m_color_value_delete;
    this->m_color_operator_delete = color.m_color_operator_delete;
    this->m_color_total_delete = color.m_color_total_delete;
    this->m_color_address_delete = color.m_color_address_delete;


    this->m_color_display_table = color.m_color_display_table;
    this->m_color_display_title = color.m_color_display_title;
    this->m_color_value_display = color.m_color_value_display;
    this->m_color_operator_display = color.m_color_operator_display;
    this->m_color_total_display = color.m_color_total_display;
    this->m_color_address_display = color.m_color_address_display;

}
void Language::read_setting() {
    this->m_index = json.m_index;
    this->m_application = json.m_application;
    this->m_name = json.m_name;
    this->m_language = json.m_language;

}
void Language::read_result() {
    this->myResult = the_result;
}


























