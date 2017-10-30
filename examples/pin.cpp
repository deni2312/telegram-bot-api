#include <iostream>
#include <tgbot/bot.h>

using namespace tgbot;
using namespace types;
using namespace methods;

void pinMsg(const Message message, const Api& api){
	try{
		api.pinChatMessage(std::to_string(message.chat.id), std::to_string(message.messageId),false);
	}catch(TelegramException& excp){
		std::cerr<<"Exception catched, it says:" << excp.what() << "\n";
	}
}

int main() {
	LongPollBot bot("token");
	bot.callback(pinMsg);
	bot.start();
	//unreachable code
}
