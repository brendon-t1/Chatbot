#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode;
class ChatLogic;

class ChatBot
{
private:
 
    wxBitmap *_image;

    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    ChatBot();
    ChatBot(std::string filename);
    ~ChatBot();

    //// STUDENT CODE
    ////
	//copy constructor
    ChatBot(const ChatBot &source);
    //copy assignment operator
    ChatBot &operator=(const ChatBot &source); 
    //move constructor
    ChatBot(ChatBot &&source); 
    //move assignment operator
    ChatBot &operator=(ChatBot &&source); 
    ////
    //// EOF STUDENT CODE

    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    void ReceiveMessageFromUser(std::string message);
};

#endif 