import nltk
from nltk.chat.util import Chat, reflections


pairs = [
    (r"hi|hello|hey", ["Hello!", "Hi there!", "Hey!"]), 
    (r"\b(?:how are you)\b", ["I'm good, thank you!", "I'm doing well, how about you?"]),
    (r"\b(?:Fine|Well|Great)\b",["That's great! How can I help you?"]),
    (r"(.*) your name?", ["I'm a chatbot!", "I don't really have a name."]),
    (r"quit", ["Bye!", "Goodbye!", "Have a great day!"]),
    (r"\b(?:My Name is)\b",["Nice to meet you!, I am happy to assist you!"]),
    (r"\b(?:Cloud computing)\b",["According to AWS Cloud computing is the on-demand delivery of IT resources over the Internet with pay-as-you-go pricing. Instead of buying, owning, and maintaining physical data centers and servers, you can access technology services, such as computing power, storage, and databases, on an as-needed basis from a cloud provider like Amazon Web Services (AWS)."]),
    (r"What actually you work for?",["I can suggest you anything related to Fitness!"]),
    (r"How many hours do i need to workout to remain fit|How can i achieve good physique?",["Atleast minimum 1 hour you should indulge yourself in fitness"]),
    (r"\b(?:Suggest me good workout split to follow)\b",["Here is you can follow\n Monday: Back \n Tuesday:Chest \n Wednesday:Shoulder \n Thursday:Legs \n Friday:Arms \n Saturday:Cardio Abs"]),
    (r"\b(?:How many exercise do i need to perform)\b",["According to my knowledge you should perform 5-6 exercise for each muscle group!"]),
    (r"\b(?:Suggest some exercise for back)\b",[
        "List of back Exercise: \n -> Deadlift \n -> Bent over Rowing \n -> lat Pull down \n -> Pull Over \n -> PullUps "
    ]),
    (r"\b(?:Chest)\b",[
        "List of chest Exercise: \n -> Incline Bench press \n -> Bench press \n -> Decline press \n -> Machine fly \n -> Pushups"
    ]),
    (r"\b(?:Legs)\b",[
        "List of Legs Exercise: \n -> Squat \n -> Leg Press \n -> Leg Extensions \n -> Leg Curls \n -> Lunges \n -> Calf raises"
    ]),
   (r"\b(?:Shoulder)\b",[
        "List of Shoulder Exercise: \n -> Shoulder Press \n -> Military Press \n -> Lateral Raises \n -> Front Raises \n -> Face Pull"
    ]),
    (r"\b(?:Arms)\b",[
        "List of Arms Exercise: \n -> Skull Crusher \n -> Dumber curl \n -> Pushdown \n -> StraightBar Curl\n -> Dip"
    ]),
]




chatbot = Chat(pairs, reflections)

def chat_with_bot():
    print("Hi! I'm a chatbot. Welcome to Customer Interaction Application!!!!")
    while True:
        user_input = input("You: ")
        response = chatbot.respond(user_input)
        print("Bot:", response)
        if user_input.lower() == "quit":
            break


if __name__ == "__main__":
    chat_with_bot()
