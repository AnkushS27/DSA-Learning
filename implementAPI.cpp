// This question comes in Amazon Inter coding test held at 20/01/23

vector<string> implementAPI(vector<string> logs) {
    unordered_map<string, string> registered_users;
    unordered_map<string, bool> logged_in_users;
    vector<string> results;

    for (auto log : logs) {
        string command, username, password;
        stringstream ss(log);
        ss >> command >> username;
        if (command == "register") {
            ss >> password;
            if (registered_users.count(username) == 0) {
                registered_users[username] = password;
                results.push_back("Registered Successfully");
            } else {
                results.push_back("Username already exists");
            }
        } else if (command == "login") {
            ss >> password;
            if (registered_users.count(username) == 0) {
                results.push_back("Login Unsuccessful");
            } else if (logged_in_users[username]) {
                results.push_back("Login Unsuccessful");
            } else if (registered_users[username] != password) {
                results.push_back("Login Unsuccessful");
            } else {
                logged_in_users[username] = true;
                results.push_back("Logged In Successfully");
            }
        } else if (command == "logout") {
            if (logged_in_users.count(username) == 0 || !logged_in_users[username]) {
                results.push_back("Logout Unsuccessful");
            } else {
                logged_in_users[username] = false;
                results.push_back("Logged Out Successfully");
            }
        }
    }

    return results;
}
