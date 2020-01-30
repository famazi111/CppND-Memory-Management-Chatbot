#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.emplace_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.emplace_back(std::unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    _chatBot = ChatBot(std::move(chatbot));
    _chatBot.SetRootNode(_chatBot.GetRootNode());
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    ChatBot chat_bot = ChatBot("../images/chatbot.png");
    chat_bot.SetRootNode(_chatBot.GetRootNode());
  	chat_bot.SetChatLogicHandle(_chatBot.GetChatLogicHandle());
    newNode->MoveChatbotHere(std::move(chat_bot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return ((_childEdges[index]).get());

    ////
    //// EOF STUDENT CODE
}