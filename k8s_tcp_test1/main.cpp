#include "tcp.hpp"
#define port 40145
#define num_of_node 2
#define server_ip "172.16.46.84"
#define buf_size 1024 //버프사이즈 정의

string node[num_of_node] = {server_ip,"172.16.46.85"};

int main(int argc, char* argv[]){
    if(argc != 2)
    {
        std::cout << argv[0] << " MY IP" << std::endl;
        exit(1);
    }
    vector<int> sock_idx;
    TCP tcp;
    tcp.connect_tcp(argv[1], node, num_of_node, port);


    int *clnt_socks = tcp.client_sock();
    for(int idx=0; idx < num_of_node;idx++){
        if(clnt_socks[idx]!=0){
            sock_idx.push_back(idx);
        }
    }
    char msg[100] = "hello world!";
    if (strcmp(argv[1],server_ip) == 0){
        tcp.send_msg(msg, sock_idx[0]);
        cerr << "SEND SUCCESS" << endl;
    }
    else{
        tcp.recv_msg(sock_idx[0]);
    }

    while(1){
        cout << "이걸 보고 계신다면" << endl;
        cout << "성공 하신겁니다." << endl;
        sleep(5);
    }

  return 0;
}