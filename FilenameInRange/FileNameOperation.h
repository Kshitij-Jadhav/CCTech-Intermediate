#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class FileNameOperation{
private:
    string FileName;
    string Selected;
    void getFileName();
    void removeSpecificWord();
    bool isExtension(std::string extension);
    void removeFileExtension();
    void removeFilePath();
public:
    pair<int, int> getFilenameRange(string fileName);
};

pair<int, int> FileNameOperation :: getFilenameRange(string fileName) {
    FileName = fileName;
    getFileName();
    int firstPosition = fileName.find(Selected);
    int secondPosition = firstPosition + (Selected.size());
    return {firstPosition, secondPosition};
}

void FileNameOperation::getFileName() {
    Selected = FileName;
    removeFileExtension();
    removeFilePath();
    removeSpecificWord();
}

void FileNameOperation::removeFileExtension() {
    int position = Selected.find_last_of(".");
    if(position == string::npos)
        return;
    if (isExtension(Selected.substr(position)))
        Selected.erase(Selected.begin() + position, Selected.end());
}

void FileNameOperation::removeFilePath() {
    int position = Selected.find_last_of("/");
    if(position == string::npos)
        return;
    Selected.erase(Selected.begin(), Selected.begin() + (position + 1));
}

void FileNameOperation::removeSpecificWord() {
    vector<string> specificWord = {"tests", "test", "spec", "step"};
    string loweredFileName = Selected;
    transform(loweredFileName.begin(), loweredFileName.end(), loweredFileName.begin(), ::tolower);
    for(int i = 0; i < specificWord.size(); i++){
        if(loweredFileName.find(specificWord.at(i)) != string::npos){
            int position = loweredFileName.find(specificWord.at(i));
            char c;
            if(position != string::npos) {
                vector<char> separator = {'.', '_', '-'};
                for( char sep : separator){
                    if(Selected[position - 1] == sep){
                        Selected.erase(position - 1, 1);
                        position--;
                        break;
                    }
                    else if(Selected[position + specificWord.at(i).size()] == sep){
                        Selected.erase(position + specificWord.at(i).size(), 1);
                        break;
                    }
                }
                Selected.erase(Selected.begin() + position,Selected.begin() + position + (specificWord.at(i).size()));
                break;
            }
        }
    }
}

bool FileNameOperation::isExtension(string extension) {
    vector <string> extensions = {".re", ".exs", ".rb", ".py", ".sh", ".coffee", ".chpl", ".c", ".cpp", ".cs", ".java", ".kt", ".php",
                                  ".js", ".ts", ".erl", ".clj", ".d", ".go", ".R", ".swift", ".groovy", ".feature",".fun", ".t", ".plt"};
    for(string ex : extensions)
        if(ex == extension)
            return true;
    return false;
}