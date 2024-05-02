class App{
private:
    Json m_json;
public:
    App(Json* json, AddSearchEdit *add, AddSearchEdit *search, AddSearchEdit *edit, std::vector<std::vector<Input>> *the_result, Table *table, Colors *color, Main *main, Dialog *dialog, Help *help, Confirm *confirm, Delete *m_delete) {
        std::vector<std::string> names = { "addition", "search", "edit" };
        *json = this->read_setting();
        this->m_json = *json;
        const int size = 3;
        AddSearchEdit add_search_edit[size];
        for (int i = 0; i < names.size(); i++)
            add_search_edit[i] = this->read_add_search_edit(names[i]);

        *add = add_search_edit[0];
        *search = add_search_edit[1];
        *edit = add_search_edit[2];

        *the_result = this->read_result();
        *table = this->read_table();
        *color = this->read_colors();
        *main = this->read_main();
        *dialog = this->read_dialog();
        *help = this->read_help();
        *confirm = this->read_confirm();
        *m_delete = this->read_delete();
    }
     std::vector<std::vector<Input>> read_result();
     Table read_table();
     Colors read_colors();
     Main read_main();
     Dialog read_dialog();
     Help read_help();
     AddSearchEdit read_add_search_edit(std::string name);
     Confirm read_confirm();
     Delete read_delete();
     void write_result(std::vector<std::vector<Input>> result);
     Json read_setting();
};

Table App::read_table() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["tables"].template get<Table>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Colors App::read_colors() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["color"].template get<Colors>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Main App::read_main() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        Main m_main = JsonFile["eng"]["main"].template get<Main>();
        if (m_main.m_input_key_add == m_main.m_input_key_search) {
            m_main.m_input_key_add = m_main.m_input_key_add + "1";
            m_main.m_input_key_search = m_main.m_input_key_search + "2";
        }
        return m_main;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Dialog App::read_dialog() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["dialog"].template get<Dialog>();
        //return add;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Help App::read_help() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["help"].template get<Help>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
AddSearchEdit App::read_add_search_edit(std::string name) {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);

        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);

        return  JsonFile["eng"][name].template get<AddSearchEdit>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Confirm App::read_confirm() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        Confirm confirm = JsonFile["eng"]["confirm"].template get<Confirm>();
        if (confirm.m_input_key_edit == confirm.m_input_key_delete) {
            confirm.m_input_key_edit = confirm.m_input_key_edit + "1";
            confirm.m_input_key_delete = confirm.m_input_key_delete + "2";
        }
        return confirm;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Delete App::read_delete() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        return JsonFile["eng"]["delete"].template get<Delete>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
std::vector<std::vector<Input>> App::read_result() {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile =
            m_json.m_application != "" && m_json.m_name != "" ?
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name) :
            nlohmann::json::parse(MyReadFile).at("data").at(m_json.m_index);
        nlohmann::json myResult = JsonFile["result"];
        std::vector<std::vector<Input>> vec;
        for (int i = 0; i < myResult.size(); i++) {
            vec.push_back(std::vector<Input>());
            for (int ii = 0; ii < myResult.at(i).size(); ii++) {
                Input inp = myResult.at(i).at(ii).template get<Input>();
                vec[i].push_back(inp);
            }
        }

        return vec;
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
void App::write_result(std::vector<std::vector<Input>> result) {
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile = nlohmann::json::parse(MyReadFile);
        if (m_json.m_application != "" && m_json.m_name != "") 
            JsonFile.at("data").at(m_json.m_index).at(m_json.m_application).at(m_json.m_name)["result"] = result;
        else
            JsonFile.at("data").at(m_json.m_index)["result"] = result;
        std::ofstream myfile;
        myfile.open(TEXT_FIE_PATH);
        myfile << JsonFile;
        myfile.close();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
Json App::read_setting(){
    try {
        std::ifstream MyReadFile(TEXT_FIE_PATH);
        nlohmann::json JsonFile = nlohmann::json::parse(MyReadFile);
        return JsonFile.template get<Json>();
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: result" << e.what() << std::endl;
    }
}
