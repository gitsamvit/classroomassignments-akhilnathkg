#include<string>
#include<iostream>
using namespace std;

//pure abstract class
class IcommunicationManger {
public:
    virtual void shareContent(string imageLink) = 0; //abstract method
};

class ImageGallery {
private:
    string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg" };
public:

    // share 
    void share(int index, IcommunicationManger* comManager) {
        comManager->shareContent(images[index]);
    }
};

class BluetoothManager : public IcommunicationManger {
public:
    void searchDevices() {}
    void pairdevice() {}
    void sendContent(int id) {}
    void turnOn() {}
    void turnOff() {}
    BluetoothManager() {}
    void shareContent(string imageLink) {
        cout << "image shared via Bluetooth" << endl;
    }
};

class WhatsAppManager : public IcommunicationManger {
public:
    void turnOn() {}
    void turnOff() {}
    void shareContent(int id) {}
    void joinGroup() {}
    void addMember() {}
    void createGroup() {}
    WhatsAppManager() {}
    void shareContent(string imageLink) {
        cout << "image shared via Whatsapp" << endl;
    }
};

class MailManager : public IcommunicationManger {
public:
    void pullNewMails() {}
    void senMails() {}
    void composeEmail() {}
    void addAttachement() {}
    MailManager() {}
    void shareContent(string imageLink) {
        cout << "image shared via Mail" << endl;
    }
};

int main() {
    MailManager* _mailManager = new  MailManager();
    BluetoothManager* _BluetoothManager = new  BluetoothManager();
    WhatsAppManager* _WhatsAppManager = new  WhatsAppManager();

    ImageGallery* imageMgmt = new  ImageGallery();
    imageMgmt->share(0, _BluetoothManager);

}