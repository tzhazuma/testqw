// <stlmain> contains a lot header of stl ,because bits/stdc++.h only in gcc,so I made this to use it in msvc
//this #include<stlmain> can be replaced by import std;
#include <stlmain>
//base struct to let all structs can be put into a vector and use virtual function to refresh and show
struct base{
    virtual void refresh(const vector<string>& package){}
    virtual void show(){}
};
// all structs,with refresh and show function,all member variables are public that can easy get from outside
struct ext_game_status_t:public base{
    uint8_t game_type=4;
    uint8_t game_progress=4;
    uint16_t stage_remain_time;
    uint64_t SyncTimeStamp;
    map<uint8_t ,string> game_type_map{
            {1,"master"},
            {2,"master_single"},
            {3,"ICRA"},
            {4,"legal 3v3"},
            {5,"legal 1v1"}
    };
    map<uint8_t ,string> game_progress_map{
            {0,"not start"},
            {1,"prepare"},
            {2,"self-check"},
            {3,"5s count down"},
            {4,"running"},
            {5,"computing result"}
    };
    void refresh(const vector<string>& package) override {
        game_type = stoi(string{package[7][0]}, nullptr, 16);
        game_progress = stoi(string{package[7][1]}, nullptr, 16);
        stage_remain_time = stoi(package[8] + package[9], nullptr, 16);
        SyncTimeStamp = stoll(
                package[11] + package[12] + package[13] + package[14] + package[15] + package[16] + package[17] +
                package[10], nullptr, 16);
    }
    void show()  override{cout<<"game_type:"<<game_type_map[game_type]<<"game_progress:"<<game_progress_map[game_progress]<<endl;}
};
struct ext_game_result_t:public base{
    uint8_t winner;
     void refresh(const vector<string>& package) override{
        winner=stoi(package[7],nullptr,16);
    }
    map<uint8_t ,string> winner_map{
            {0,"draw"},
            {1,"red"},
            {2,"blue"}
    };
     void show() override{cout<<"winner:"<<winner_map[winner]<<endl;}
};
struct ext_game_robot_HP_t:public base{
    uint16_t red_1_robot_HP;
    uint16_t red_2_robot_HP;
    uint16_t red_3_robot_HP;
    uint16_t red_4_robot_HP;
    uint16_t red_5_robot_HP;
    uint16_t red_7_robot_HP;
    uint16_t red_outpost_HP;
    uint16_t red_base_HP;
    uint16_t blue_1_robot_HP;
    uint16_t blue_2_robot_HP;
    uint16_t blue_3_robot_HP;
    uint16_t blue_4_robot_HP;
    uint16_t blue_5_robot_HP;
    uint16_t blue_7_robot_HP;
    uint16_t blue_outpost_HP;
    uint16_t blue_base_HP;
    void refresh(const vector<string>& package) override{
        red_1_robot_HP=stoi(package[7]+package[8],nullptr,16);
        red_2_robot_HP=stoi(package[9]+package[10],nullptr,16);
        red_3_robot_HP=stoi(package[11]+package[12],nullptr,16);
        red_4_robot_HP=stoi(package[13]+package[14],nullptr,16);
        red_5_robot_HP=stoi(package[15]+package[16],nullptr,16);
        red_7_robot_HP=stoi(package[17]+package[18],nullptr,16);
        red_outpost_HP=stoi(package[19]+package[20],nullptr,16);
        red_base_HP=stoi(package[21]+package[22],nullptr,16);
        blue_1_robot_HP=stoi(package[23]+package[24],nullptr,16);
        blue_2_robot_HP=stoi(package[25]+package[26],nullptr,16);
        blue_3_robot_HP=stoi(package[27]+package[28],nullptr,16);
        blue_4_robot_HP=stoi(package[29]+package[30],nullptr,16);
        blue_5_robot_HP=stoi(package[31]+package[32],nullptr,16);
        blue_7_robot_HP=stoi(package[33]+package[34],nullptr,16);
        blue_outpost_HP=stoi(package[35]+package[36],nullptr,16);
        blue_base_HP=stoi(package[37]+package[38],nullptr,16);
    }
    void show() override{
        cout<<"red_1_robot_HP:"<<red_1_robot_HP<<endl;
        cout<<"red_2_robot_HP:"<<red_2_robot_HP<<endl;
        cout<<"red_3_robot_HP:"<<red_3_robot_HP<<endl;
        cout<<"red_4_robot_HP:"<<red_4_robot_HP<<endl;
        cout<<"red_5_robot_HP:"<<red_5_robot_HP<<endl;
        cout<<"red_7_robot_HP:"<<red_7_robot_HP<<endl;
        cout<<"red_outpost_HP:"<<red_outpost_HP<<endl;
        cout<<"red_base_HP:"<<red_base_HP<<endl;
        cout<<"blue_1_robot_HP:"<<blue_1_robot_HP<<endl;
        cout<<"blue_2_robot_HP:"<<blue_2_robot_HP<<endl;
        cout<<"blue_3_robot_HP:"<<blue_3_robot_HP<<endl;
        cout<<"blue_4_robot_HP:"<<blue_4_robot_HP<<endl;
        cout<<"blue_5_robot_HP:"<<blue_5_robot_HP<<endl;
        cout<<"blue_7_robot_HP:"<<blue_7_robot_HP<<endl;
        cout<<"blue_outpost_HP:"<<blue_outpost_HP<<endl;
        cout<<"blue_base_HP:"<<blue_base_HP<<endl;
    }
};
struct ext_ICRA_buff_debuff_zone_and_lurk_status_t:public base{
    uint8_t F1_zone_status=1;
    uint8_t F1_zone_buff_debuff_status=3;
    uint8_t F2_zone_status=1;
    uint8_t F2_zone_buff_debuff_status=3;
    uint8_t F3_zone_status=1;
    uint8_t F3_zone_buff_debuff_status=3;
    uint8_t F4_zone_status=1;
    uint8_t F4_zone_buff_debuff_status=3;
    uint8_t F5_zone_status=1;
    uint8_t F5_zone_buff_debuff_status=3;
    uint8_t F6_zone_status=1;
    uint8_t F6_zone_buff_debuff_status=3;
    uint16_t red1_bullet_left;
    uint16_t red2_bullet_left;
    uint16_t blue1_bullet_left;
    uint16_t blue2_bullet_left;
    uint8_t lurk_mode;
    uint8_t res;
    void refresh(const vector<string>& package) override{
        const auto temp=package[7]+package[8]+package[9];
        F1_zone_status=stoi(temp.substr(0,1),nullptr,16)/8;
        F1_zone_buff_debuff_status=stoi(temp.substr(0,1),nullptr,16)%8;
        F2_zone_status=stoi(temp.substr(1,1),nullptr,16)/8;
        F2_zone_buff_debuff_status=stoi(temp.substr(1,1),nullptr,16)%8;
        F3_zone_status=stoi(temp.substr(2,1),nullptr,16)/8;
        F3_zone_buff_debuff_status=stoi(temp.substr(2,1),nullptr,16)%8;
        F4_zone_status=stoi(temp.substr(3,1),nullptr,16)/8;
        F4_zone_buff_debuff_status=stoi(temp.substr(3,1),nullptr,16)%8;
        F5_zone_status=stoi(temp.substr(4,1),nullptr,16)/8;
        F5_zone_buff_debuff_status=stoi(temp.substr(4,1),nullptr,16)%8;
        F6_zone_status=stoi(temp.substr(5,1),nullptr,16)/8;
        F6_zone_buff_debuff_status=stoi(temp.substr(5,1),nullptr,16)%8;
        red1_bullet_left=stoi(package[10]+package[11],nullptr,16);
        red2_bullet_left=stoi(package[12]+package[13],nullptr,16);
        blue1_bullet_left=stoi(package[14]+package[15],nullptr,16);
        blue2_bullet_left=stoi(package[16]+package[17],nullptr,16);
        lurk_mode=stoi(package[18],nullptr,16);
        res=stoi(package[19],nullptr,16);
    }
    map<uint8_t,string> zone_status_map={
        {0,"zone is not activated"},
        {1,"zone is activated"}
    };
    map<uint8_t,string> zone_buff_debuff_status_map={
            {1,"red_HP_recovery"},
            {3,"blue_HP_recovery"},
            {2,"red_bullet_recovery"},
            {4,"blue_bullet_recovery"},
            {5,"None shoot"},
            {6,"None move"},
    };
    map<uint8_t,string> lurk_mode_map={
            {0,"normal"},
            {1,"preparing"},
            {2,"lurking"}
    };
    void show() override{
        cout<<"F1_zone_status:"<<zone_status_map[F1_zone_status]<<endl;
        cout<<"F1_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F1_zone_buff_debuff_status]<<endl;
        cout<<"F2_zone_status:"<<zone_status_map[F2_zone_status]<<endl;
        cout<<"F2_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F2_zone_buff_debuff_status]<<endl;
        cout<<"F3_zone_status:"<<zone_status_map[F3_zone_status]<<endl;
        cout<<"F3_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F3_zone_buff_debuff_status]<<endl;
        cout<<"F4_zone_status:"<<zone_status_map[F4_zone_status]<<endl;
        cout<<"F4_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F4_zone_buff_debuff_status]<<endl;
        cout<<"F5_zone_status:"<<zone_status_map[F5_zone_status]<<endl;
        cout<<"F5_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F5_zone_buff_debuff_status]<<endl;
        cout<<"F6_zone_status:"<<zone_status_map[F6_zone_status]<<endl;
        cout<<"F6_zone_buff_debuff_status:"<<zone_buff_debuff_status_map[F6_zone_buff_debuff_status]<<endl;
        cout<<"red1_bullet_left:"<<red1_bullet_left<<endl;
        cout<<"red2_bullet_left:"<<red2_bullet_left<<endl;
        cout<<"blue1_bullet_left:"<<blue1_bullet_left<<endl;
        cout<<"blue2_bullet_left:"<<blue2_bullet_left<<endl;
        cout<<"lurk_mode:"<<lurk_mode_map[lurk_mode]<<endl;
    }
};
struct ext_event_data_t:public base{
    uint32_t event_type;
    void refresh(const vector<string>& package) override{
        event_type=stoi(package[7]+package[8]+package[9]+package[10],nullptr,16);
    }
    void show()override{
        auto temp=event_type>>21;
        if(temp%2==1){
            cout<<"outpose alive"<<endl;
        }
        else
            cout<<"outpose dead"<<endl;
        if((temp%4)/2==1){
            cout<<"base protect alive"<<endl;
        }
        else
            cout<<"base protect dead"<<endl;
        if((temp%8)/4==1){
            cout<<"R4/B4 captured"<<endl;
        }
        else
            cout<<"R4/B4 not captured"<<endl;
        if((temp%16)/8==1){
            cout<<"R3/B3 captured"<<endl;
        }
        else
            cout<<"R3/B3 not captured"<<endl;
        if((temp%32)/16==1){
            cout<<"R2/B2 captured"<<endl;
        }
        else
            cout<<"R2/B2 not captured"<<endl;
        if((temp%64)/32==1){
            cout<<"Great energy active"<<endl;
        }
        else
            cout<<"Great energy not active"<<endl;
        if((temp%128)/64==1){
            cout<<"Small energy active"<<endl;
        }
        else
            cout<<"Small energy not active"<<endl;
        if((temp%256)/128==1){
            cout<<"HitPoint captured"<<endl;
        }
        else
            cout<<"HitPoint not captured"<<endl;
        if((temp%512)/256==1){
            cout<<"3HP recovery point captured"<<endl;
        }
        else
            cout<<"3HP recovery point not captured"<<endl;
        if((temp%1024)/512==1){
            cout<<"2HP recovery point captured"<<endl;
        }
        else
            cout<<"2HP recovery point not captured"<<endl;
        if((temp%2048)/1024==1){
            cout<<"1HP recovery point captured"<<endl;
        }
        else
            cout<<"1HP recovery point not captured"<<endl;
    }
};
struct ext_supply_projectile_action_t:public base{
    uint8_t  supply_projectile_id;
    uint8_t  supply_robot_id;
    uint8_t  supply_projectile_step;
    uint8_t  supply_projectile_num;
    void refresh(const vector<string>& package) override{
        supply_projectile_id=stoi(package[7],nullptr,16);
        supply_robot_id=stoi(package[8],nullptr,16);
        supply_projectile_step=stoi(package[9],nullptr,16);
        supply_projectile_num=stoi(package[10],nullptr,16);
    }
    map<uint8_t,string> supply_robot_id_map{
            {0,"none"},
            {1,"red_hero"},
            {2,"red_engineer"},
            {3,"red_inf"},
            {4,"red_inf"},
            {5,"red_inf"},
            {101,"blue_hero"},
            {102,"blue_engineer"},
            {103,"blue_inf"},
            {104,"blue_inf"},
            {105,"blue_inf"}
    };
    map<uint8_t,string> supply_projectile_step_map{
            {0,"close"},
            {1,"prepareing"},
            {2,"falling"}
    };
    void show()override{
        cout<<"supply_projectile_id:"<<supply_projectile_id<<endl;
        cout<<"supply_robot_id:"<<supply_robot_id_map[supply_robot_id]<<endl;
        cout<<"supply_projectile_step:"<<supply_projectile_step_map[supply_projectile_step]<<endl;
        cout<<"supply_projectile_num:"<<supply_projectile_num<<endl;
    }
};
struct exf_referee_warning_t:public base{
    uint8_t level;
    uint8_t foul_robot_id;
    void refresh(const vector<string>& package) override{
        level=stoi(package[7],nullptr,16);
        foul_robot_id=stoi(package[8],nullptr,16);
    }
    map<uint8_t,string> level_map{
            {1,"yellow"},
            {2,"red"},
            {3,"fail"}
    };
    map<uint8_t,string> foul_robot_id_map{
            {0,"fail"},
            {1,"red_hero"},
            {2,"red_engineer"},
            {3,"red_inf"},
            {4,"red_inf"},
            {5,"red_inf"},
            {101,"blue_hero"},
            {102,"blue_engineer"},
            {103,"blue_inf"},
            {104,"blue_inf"},
            {105,"blue_inf"}
    };
    void show()override{
        cout<<"level:"<<level_map[level]<<endl;
        cout<<"foul_robot_id:"<<foul_robot_id_map[foul_robot_id]<<endl;
    }
};
struct ext_dart_remaining_time_t:public base{
    uint8_t  dart_remaining_time;
    void refresh(const vector<string>& package) override{
        dart_remaining_time=stoi(package[7],nullptr,16);
    }
    void show()override{
        cout<<"dart_remaining_time:"<<dart_remaining_time<<endl;
    }
};
struct ext_game_robot_status_t:public base{
uint8_t robot_id;
uint8_t robot_level;
uint16_t remain_HP;
uint16_t max_HP;
uint16_t shooter_id1_17mm_cooling_rate;
uint16_t shooter_id1_17mm_cooling_limit;
uint16_t shooter_id1_17mm_speed_limit;
uint16_t shooter_id2_17mm_cooling_rate;
uint16_t shooter_id2_17mm_cooling_limit;
uint16_t shooter_id2_17mm_speed_limit;
uint16_t shooter_id1_42mm_cooling_rate;
uint16_t shooter_id1_42mm_cooling_limit;
uint16_t shooter_id1_42mm_speed_limit;
uint16_t chassis_power_limit;
uint8_t mains_power_gimbal_output=1;
uint8_t mains_power_chassis_output=1;
uint8_t mains_power_shooter_output=1;
void refresh(const vector<string>& package) override{
robot_id=stoi(package[7],nullptr,16);
robot_level=stoi(package[8],nullptr,16);
remain_HP=stoi(package[9]+package[10],nullptr,16);
max_HP=stoi(package[11]+package[12],nullptr,16);
shooter_id1_17mm_cooling_rate=stoi(package[13]+package[14],nullptr,16);
shooter_id1_17mm_cooling_limit=stoi(package[15]+package[16],nullptr,16);
shooter_id1_17mm_speed_limit=stoi(package[17]+package[18],nullptr,16);
shooter_id2_17mm_cooling_rate=stoi(package[19]+package[20],nullptr,16);
shooter_id2_17mm_cooling_limit=stoi(package[21]+package[22],nullptr,16);
shooter_id2_17mm_speed_limit=stoi(package[23]+package[24],nullptr,16);
shooter_id1_42mm_cooling_rate=stoi(package[25]+package[26],nullptr,16);
shooter_id1_42mm_cooling_limit=stoi(package[27]+package[28],nullptr,16);
shooter_id1_42mm_speed_limit=stoi(package[29]+package[30],nullptr,16);
chassis_power_limit=stoi(package[31]+package[32],nullptr,16);
auto temp=stoi(string{package[33][0]},nullptr,16);
mains_power_gimbal_output=temp/8;
mains_power_chassis_output=(temp%8)/4;
mains_power_shooter_output=(temp%4)/2;
}
map<uint8_t,string> robot_id_map{
        {1,"red_hero"},
        {2,"red_engineer"},
        {3,"red_inf"},
        {4,"red_inf"},
        {5,"red_inf"},
        {6,"red_air"},
        {7,"red_guard"},
        {8,"red_dart"},
        {9,"red_rader"},
        {101,"blue_hero"},
        {102,"blue_engineer"},
        {103,"blue_inf"},
        {104,"blue_inf"},
        {105,"blue_inf"},
        {106,"blue_air"},
        {107,"blue_guard"},
        {108,"blue_dart"},
        {109,"blue_rader"}
};
void show()override{
    cout<<"robot_id:"<<robot_id_map[robot_id]<<endl;
    cout<<"robot_level:"<<robot_level<<endl;
    cout<<"remain_HP:"<<remain_HP<<endl;
    cout<<"max_HP:"<<max_HP<<endl;
    cout<<"shooter_id1_17mm_cooling_rate:"<<shooter_id1_17mm_cooling_rate<<endl;
    cout<<"shooter_id1_17mm_cooling_limit:"<<shooter_id1_17mm_cooling_limit<<endl;
    cout<<"shooter_id1_17mm_speed_limit:"<<shooter_id1_17mm_speed_limit<<endl;
    cout<<"shooter_id2_17mm_cooling_rate:"<<shooter_id2_17mm_cooling_rate<<endl;
    cout<<"shooter_id2_17mm_cooling_limit:"<<shooter_id2_17mm_cooling_limit<<endl;
    cout<<"shooter_id2_17mm_speed_limit:"<<shooter_id2_17mm_speed_limit<<endl;
    cout<<"shooter_id1_42mm_cooling_rate:"<<shooter_id1_42mm_cooling_rate<<endl;
    cout<<"shooter_id1_42mm_cooling_limit:"<<shooter_id1_42mm_cooling_limit<<endl;
    cout<<"shooter_id1_42mm_speed_limit:"<<shooter_id1_42mm_speed_limit<<endl;
    cout<<"chassis_power_limit:"<<chassis_power_limit<<endl;
    cout<<"mains_power_gimbal_output:"<<mains_power_gimbal_output<<endl;
    cout<<"mains_power_chassis_output:"<<mains_power_chassis_output<<endl;
    cout<<"mains_power_shooter_output:"<<mains_power_shooter_output<<endl;
    }
};
struct ext_power_heat_data_t:public base{
    uint16_t chassis_volt;
    uint16_t chassis_current;
    float chassis_power;
    uint16_t chassis_power_buffer;
    uint16_t shooter_id1_17mm_cooling_heat;
    uint16_t shooter_id2_17mm_cooling_heat;
    uint16_t shooter_id1_42mm_cooling_heat;
    void refresh(const vector<string>& package) override{
    chassis_volt=stoi(package[7]+package[8],nullptr,16);
    chassis_current=stoi(package[9]+package[10],nullptr,16);
    chassis_power=stoi(package[11]+package[12]+package[13]+package[14],nullptr,16);
    chassis_power_buffer=stoi(package[15]+package[16],nullptr,16);
    shooter_id1_17mm_cooling_heat=stoi(package[17]+package[18],nullptr,16);
    shooter_id2_17mm_cooling_heat=stoi(package[19]+package[20],nullptr,16);
    shooter_id1_42mm_cooling_heat=stoi(package[21]+package[22],nullptr,16);
    }
    void show()override{
        cout<<"chassis_volt:"<<chassis_volt<<endl;
        cout<<"chassis_current:"<<chassis_current<<endl;
        cout<<"chassis_power:"<<chassis_power<<endl;
        cout<<"chassis_power_buffer:"<<chassis_power_buffer<<endl;
        cout<<"shooter_id1_17mm_cooling_heat:"<<shooter_id1_17mm_cooling_heat<<endl;
        cout<<"shooter_id2_17mm_cooling_heat:"<<shooter_id2_17mm_cooling_heat<<endl;
        cout<<"shooter_id1_42mm_cooling_heat:"<<shooter_id1_42mm_cooling_heat<<endl;
        }
};
struct ext_game_robot_pos_t:public base{
    float x;
    float y;
    float z;
    float yaw;
    void refresh (const vector<string>& package) override{
        x=stoi(package[7]+package[8]+package[9]+package[10],nullptr,16);
        y=stoi(package[11]+package[12]+package[13]+package[14],nullptr,16);
        z=stoi(package[15]+package[16]+package[17]+package[18],nullptr,16);
        yaw=stoi(package[19]+package[20]+package[21]+package[22],nullptr,16);
    }
    void show()override{
        cout<<"x:"<<x<<"m"<<endl;
        cout<<"y:"<<y<<"m"<<endl;
        cout<<"z:"<<z<<"m"<<endl;
        cout<<"yaw:"<<yaw<<"degree"<<endl;
        }
};
struct ext_buff_t:public base{
    uint8_t power_rune_buff;
    void refresh(const vector<string>& package) override{
        power_rune_buff=stoi(string{package[7][0]},nullptr,16);
    }
    void show()override{
    cout<<"robot_HP_recovery"<<power_rune_buff/8<<endl;
    cout<<"robot_heat_cooling_accelerate"<<(power_rune_buff%8)/4<<endl;
    cout<<"robot_shoot_defend_improve"<<(power_rune_buff%4)/2<<endl;
    cout<<"robot_shoot_attack_improve"<<power_rune_buff%2<<endl;
    }
};
struct aerial_robot_energy_t:public base{
    uint8_t attack_time;
    void refresh(const vector<string>& package) override{
        attack_time=stoi(package[7],nullptr,16);
    }
    void show()override{
        cout<<"attack_time:"<<attack_time<<endl;
    }
};
struct ext_robot_hurt_t:public base{
    uint8_t armor_id=4;
    uint8_t hurt_type=4;
    void refresh(const vector<string>& package) override{
        armor_id=stoi(package[7],nullptr,16);
        hurt_type=stoi(package[8],nullptr,16);
    }
    map<uint8_t,string> hurt_type_map=
            {{0,"armor attacked"},
             {1,"modules offline"},
             {2,"over shooting speed limit"},
             {3,"over heat limit"},
             {4,"over chassis power limit"},
             {5,"armor hit"}
            };
    void show()override{
        cout<<"armor_id:"<<armor_id<<endl;
        cout<<"hurt_type:"<<hurt_type_map[hurt_type]<<endl;
    }
};
struct ext_shoot_data_t:public base{
    uint8_t bullet_type;
    uint8_t shooter_id;
    uint8_t bullet_freq;
    float bullet_speed;
    void refresh(const vector<string>& package) override{
        bullet_type=stoi(package[7],nullptr,16);
        bullet_freq=stoi(package[9],nullptr,16);
        shooter_id=stoi(package[8],nullptr,16);
        bullet_speed=stoi(package[10]+package[11]+package[12]+package[13],nullptr,16);
    }
    map<uint8_t,string> bullet_type_map=
            {{1,"17mm"},
             {2,"42mm"}
            };
    map<uint8_t,string> shooter_id_map=
            {{1,"17mm1"},
             {2,"17mm2"},
             {3,"42mm"}
            };
    void show()override{
        cout<<"bullet_type:"<<bullet_type_map[bullet_type]<<endl;
        cout<<"shooter_id:"<<shooter_id_map[shooter_id]<<endl;
        cout<<"bullet_freq:"<<bullet_freq<<endl;
        cout<<"bullet_speed:"<<bullet_speed<<endl;
    }
};
struct ext_bullet_remaining_t:public base{
  uint16_t bullet_remaining_num_17mm;
  uint16_t bullet_remaining_num_42mm;
  uint16_t coin_remaining_num;
    void refresh(const vector<string>& package) override{
        bullet_remaining_num_17mm=stoi(package[7]+package[8],nullptr,16);
        bullet_remaining_num_42mm=stoi(package[9]+package[10],nullptr,16);
        coin_remaining_num=stoi(package[11]+package[12],nullptr,16);
    }
    void show()override{
        cout<<"bullet_remaining_num_17mm:"<<bullet_remaining_num_17mm<<endl;
        cout<<"bullet_remaining_num_42mm:"<<bullet_remaining_num_42mm<<endl;
        cout<<"coin_remaining_num:"<<coin_remaining_num<<endl;
    }
};
struct ext_rfid_status_t:public base{
    uint32_t rfid_status;
    void refresh(const vector<string>& package) override{
        rfid_status=stoi(package[7]+package[8]+package[9]+package[10],nullptr,16);
    }
    void show()override{
        auto temp=rfid_status>>24;
        cout<<"base gain point status"<<temp/128<<endl;
        cout<<"highland gain point status"<<(temp%128)/64<<endl;
        cout<<"energy machine activate point status"<<(temp%64)/32<<endl;
        cout<<"ramp gain point status"<<(temp%32)/16<<endl;
        cout<<"outpost gain point status"<<(temp%16)/8<<endl;
        cout<<"HP recovery gain point status"<<(temp%8)/4<<endl;
        cout<<"engineer robot life card status"<<(temp%4)/2<<endl;
    }
};
struct ext_dart_client_cmd_t:public base{
    uint8_t dart_launch_opening_status;
    uint8_t dart_attack_target;
    uint16_t target_change_time;
    uint16_t operate_launch_cmd_time;
    void refresh(const vector<string>& package) override{
        dart_launch_opening_status=stoi(package[7],nullptr,16);
        dart_attack_target=stoi(package[8],nullptr,16);
        target_change_time=stoi(package[9]+package[10],nullptr,16);
        operate_launch_cmd_time=stoi(package[11]+package[12],nullptr,16);
    }
    map<uint8_t,string> dart_launch_opening_status_map=
            {{1,"close"},
             {0,"open"},
             {2,"opening or closing"}
             };
    map<uint8_t,string> dart_attack_target_map=
            {{0,"outpost"},
             {1,"base"},
             };
    void show()override{
        cout<<"dart_launch_opening_status:"<<dart_launch_opening_status_map[dart_launch_opening_status]<<endl;
        cout<<"dart_attack_target:"<<dart_attack_target_map[dart_attack_target]<<endl;
        cout<<"target_change_time:"<<target_change_time<<endl;
        cout<<"operate_launch_cmd_time:"<<operate_launch_cmd_time<<endl;
    }
};
struct robot_interactive_data_t:public base{
    uint16_t data_cmd_id;
    uint16_t sender_ID;
    uint16_t receiver_ID;
    struct robot_interactive_data_t_{
        uint8_t data[113];
        void refresh(const vector<string>& package) {
            auto data_length = package.size();
            for (int i = 0; i < data_length; i++) {
                data[i] = stoi(package[7 + i], nullptr, 16);
            }
        }
        void show(){
            cout<<"data:";
            for(int i=0;i<113;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
    }s1;
    struct ext_client_custom_graphic_delete_t{
        uint8_t operate_type;
        uint8_t layer;
        void refresh(const vector<string>& package) {
            operate_type=stoi(package[0],nullptr,16);
            layer=stoi(package[1],nullptr,16);
        }
        map<uint8_t,string> operate_type_map=
                {{1,"delete layer"},
                 {2,"clear all"},
                 {0,"none"}
                };
        void show(){
            cout<<"operate_type:"<<operate_type_map[operate_type]<<endl;
            cout<<"layer:"<<layer<<endl;
        }
    }s2;
    struct graphic_data_struct_t{
        uint8_t graphic_name[3];
        uint32_t operate_type=3;
        uint32_t graphic_type=3;
        uint32_t layer=4;
        uint32_t color=4;
        uint32_t start_angle=9;
        uint32_t end_angle=9;
        uint32_t width=10;
        uint32_t start_x=11;
        uint32_t start_y=11;
        uint32_t radius=10;
        uint32_t end_x=11;
        uint32_t end_y=11;
        void refresh(const vector<string>& package) {
            graphic_name[0]=stoi(package[0],nullptr,16);
            graphic_name[1]=stoi(package[1],nullptr,16);
            graphic_name[2]=stoi(package[2],nullptr,16);
            string temp1=package[3]+package[4]+package[5]+package[6];
            string temp2=package[7]+package[8]+package[9]+package[10];
            string temp3=package[11]+package[12]+package[13]+package[14];
            operate_type=stoi(temp1.substr(0,1),nullptr,16)/2;
            graphic_type=stoi(temp1.substr(0,1),nullptr,16)%2*4+stoi(temp1.substr(1,1),nullptr,16)/4;
            layer=stoi(temp1.substr(1,1),nullptr,16)%4*4+stoi(temp1.substr(2,1),nullptr,16)/4;
            color=stoi(temp1.substr(2,1),nullptr,16)%4*4+stoi(temp1.substr(3,1),nullptr,16)/4;
            start_angle=stoi(temp1.substr(3,1),nullptr,16)%4*128+stoi(temp1.substr(4,1),nullptr,16)*8+stoi(temp1.substr(5,1),nullptr,16)/2;
            end_angle=stoi(temp1.substr(5,1),nullptr,16)%2*256+stoi(temp1.substr(6,1),nullptr,16)*16+stoi(temp1.substr(7,1),nullptr,16);
            width=stoi(temp2.substr(0,2),nullptr,16)*4+stoi(temp2.substr(2,1),nullptr,16)/4;
            start_x=stoi(temp2.substr(2,1),nullptr,16)%4*512+stoi(temp2.substr(3,2),nullptr,16)*2+stoi(temp2.substr(5,1),nullptr,16)/8;
            start_y=stoi(temp2.substr(5,1),nullptr,16)%8*256+stoi(temp2.substr(6,2),nullptr,16);
            radius=stoi(temp3.substr(0,2),nullptr,16)*4+stoi(temp3.substr(2,1),nullptr,16)/4;
            end_x=stoi(temp3.substr(2,1),nullptr,16)%4*512+stoi(temp3.substr(3,2),nullptr,16)*2+stoi(temp3.substr(5,1),nullptr,16)/8;
            end_y=stoi(temp3.substr(5,1),nullptr,16)%8*256+stoi(temp3.substr(6,2),nullptr,16);
        }
        map<uint32_t,string> operate_type_map=
                {{1,"add"},
                 {3,"delete"},
                 {2,"update"},
                 {0,"none"}
                };
        map<uint32_t,string> graphic_type_map=
                {{0,"line"},
                 {4,"arc"},
                 {2,"circle"},
                 {1,"rectangle"},
                 {3,"oval"},
                 {5,"float"},
                 {6,"int"},
                 {7,"char"}
                };
        map<uint32_t,string> color_map=
                {{0, "red_blue"},
                 {1, "yellow"},
                 {2, "green"},
                 {3, "orange"},
                 {4, "wine"},
                 {5, "pink"},
                 {6, "cyan"},
                 {7, "black"},
                 {8, "white"},
                };
        void show(){
            cout<<"graphic_name:";
            for(int i=0;i<3;i++){
                cout<<graphic_name[i]<<" ";
            }
            cout<<endl;
            cout<<"operate_type:"<<operate_type_map[operate_type]<<endl;
            cout<<"graphic_type:"<<graphic_type_map[graphic_type]<<endl;
            cout<<"layer:"<<layer<<endl;
            cout<<"color:"<<color_map[color]<<endl;
            cout<<"start_angle:"<<start_angle<<endl;
            cout<<"end_angle:"<<end_angle<<endl;
            cout<<"width:"<<width<<endl;
            cout<<"start_x:"<<start_x<<endl;
            cout<<"start_y:"<<start_y<<endl;
            cout<<"radius:"<<radius<<endl;
            cout<<"end_x:"<<end_x<<endl;
            cout<<"end_y:"<<end_y<<endl;
        }
    };
    struct ext_client_custom_graphic_single_t{
        graphic_data_struct_t graphic_data_struct;
        void refresh(const vector<string>& package) {
            graphic_data_struct.refresh(package);
        }
        void show(){graphic_data_struct.show();}
       }s3;
    struct ext_client_custom_graphic_double_t{
        graphic_data_struct_t graphic_data_struct[2];
        void refresh(const vector<string>& package){
            graphic_data_struct[0].refresh(package|views::take(15)|ranges::to<vector<string>>());
            graphic_data_struct[1].refresh(package|views::drop(15)|ranges::to<vector<string>>());
        }
        void show(){graphic_data_struct[0].show();graphic_data_struct[1].show();}
        }s4;
    struct ext_client_custom_graphic_five_t{
        graphic_data_struct_t graphic_data_struct[5];
        void refresh(const vector<string>& package){
            for (auto i:views::iota(0,5)){
                graphic_data_struct[i].refresh(package|views::drop(15*i)|views::take(15)|ranges::to<vector<string>>());
            }
        }
        void show(){
            for (auto i:views::iota(0,5)){
                graphic_data_struct[i].show();
            }
        }
    }s5;
    struct ext_client_custom_graphic_seven_t{
        graphic_data_struct_t graphic_data_struct[7];
        void refresh(const vector<string>& package){
            for (auto i:views::iota(0,7)){
                graphic_data_struct[i].refresh(package|views::drop(15*i)|views::take(15)|ranges::to<vector<string>>());
            }
        }
        void show(){
            for (auto i:views::iota(0,7)){
                graphic_data_struct[i].show();
            }
        }
    }s6;
    struct ext_client_custom_character_t{
        graphic_data_struct_t graphic_data_struct;
        uint8_t data[30];
        void refresh(const vector<string>& package){
            graphic_data_struct.refresh(package|views::take(15)|ranges::to<vector<string>>());
            for (auto i:views::iota(0,30)){
                data[i]=stoi(package[15+i],nullptr,16);
            }
        }
        void show(){
            graphic_data_struct.show();
            cout<<"data:";
            for (auto i:views::iota(0,30)){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
    }s7;
    void refresh(const vector<string>& package) override{
        //get cmd id
        data_cmd_id=stoi(package[7]+package[8],nullptr,16);
        sender_ID=stoi(package[9]+package[10],nullptr,16);
        receiver_ID=stoi(package[11]+package[12],nullptr,16);
        //get package to send to sub-struct
        auto package_send_to=package|views::drop(13)|views::take(package.size()-2)|ranges::to<vector<string>>();
        if(package[7]=="02"){
            s1.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0100){
            s2.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0101){
            s3.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0102){
            s4.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0103){
            s5.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0104){
            s6.refresh(package_send_to);
        }
        else if(data_cmd_id==0x0110){
            s7.refresh(package_send_to);
        }
    }
   void show() override{
        cout<<"data_cmd_id:"<<data_cmd_id<<endl;
        cout<<"sender_ID:"<<sender_ID<<endl;
        cout<<"receiver_ID:"<<receiver_ID<<endl;
        if(data_cmd_id/0x100==0x02){
            s1.show();
        }
        else if(data_cmd_id==0x0100){
            s2.show();
        }
        else if(data_cmd_id==0x0101){
            s3.show();
        }
        else if(data_cmd_id==0x0102){
            s4.show();
        }
        else if(data_cmd_id==0x0103){
            s5.show();
        }
        else if(data_cmd_id==0x0104){
            s6.show();
        }
        else if(data_cmd_id==0x0110){
            s7.show();
        }
    }
};
struct robot_interactive_data_with_self_made_controller:public base{
    uint8_t data[30];
    void refresh(const vector<string>& package) override {
    //get length
    auto data_length = stoi(package[1] + package[2], nullptr, 16);
    for (int i = 0; i < data_length; i++) {
        data[i] = stoi(package[7 + i], nullptr, 16);
    }
   }
  void show() override {
   cout << "data:";
    for (unsigned char i: data) {
        cout << i << " ";
    }
    cout << endl;
    }
};
struct ext_robot_command_t_map_client:public base{
    float target_position_x;
    float target_position_y;
    float target_position_z;
    uint8_t command_keyboard;
    uint16_t target_robot_ID;
    map<uint8_t,string> target_robot_ID_map{
            {1,"red_hero"},
            {2,"red_engineer"},
            {3,"red_inf"},
            {4,"red_inf"},
            {5,"red_inf"},
            {6,"red_air"},
            {7,"red_guard"},
            {8,"red_dart"},
            {9,"red_rader"},
            {10,"red_outpost"},
            {11,"red_base"},
            {101,"blue_hero"},
            {102,"blue_engineer"},
            {103,"blue_inf"},
            {104,"blue_inf"},
            {105,"blue_inf"},
            {106,"blue_air"},
            {107,"blue_guard"},
            {108,"blue_dart"},
            {109,"blue_rader"},
            {110,"blue_outpost"},
            {111,"blue_base"},
    };
    void refresh(const vector<string>& package) override{
        target_position_x=stoi(package[7]+package[8]+package[9]+package[10],nullptr,16);
        target_position_y=stoi(package[11]+package[12]+package[13]+package[14],nullptr,16);
        target_position_z=stoi(package[15]+package[16]+package[17]+package[18],nullptr,16);
        command_keyboard=stoi(package[19],nullptr,16);
        target_robot_ID=stoi(package[20]+package[21],nullptr,16);
    }
    void show()override {
        cout << "target_position_x:" << target_position_x << endl;
        cout << "target_position_y:" << target_position_y << endl;
        cout << "target_position_z:" << target_position_z << endl;
        cout << "command_keyboard:" << command_keyboard << endl;
        cout << "target_robot_ID:" << target_robot_ID_map[target_robot_ID] << endl;
    }
};
struct ext_robot_command_t_controller:public base{
    int16_t mouse_x;
    int16_t mouse_y;
    int16_t mouse_z;
    int8_t left_button_down;
    int8_t right_button_down;
    uint16_t keyboard_value;
    uint16_t reserved;
    map<string,string> key_map{};
    void refresh(const vector<string>& package) override{
    mouse_x=stoi(package[7]+package[8],nullptr,16);
    mouse_y=stoi(package[9]+package[10],nullptr,16);
    mouse_z=stoi(package[11]+package[12],nullptr,16);
    left_button_down=stoi(package[13],nullptr,16);
    right_button_down=stoi(package[14],nullptr,16);
    keyboard_value=stoi(package[15]+package[16],nullptr,16);
    reserved=stoi(package[17]+package[18],nullptr,16);
    }
    auto keyboard(){
      if(keyboard_value/32768==1){
          key_map["W"]="pressed";
      }
      else{key_map["W"]="not pressed";}
      if((keyboard_value%32768)/16384==1){
          key_map["S"]="pressed";
      }
      else{key_map["S"]="not pressed";}
      if((keyboard_value%16384)/8192==1) {
            key_map["A"] = "pressed";
      }
      else{key_map["A"]="not pressed";}
      if((keyboard_value%8192)/4096==1){
            key_map["D"]="pressed";
      }
      else{key_map["D"]="not pressed";}
      if((keyboard_value%4096)/2048==1) {
          key_map["SHIFT"] = "pressed";
      }
      else{key_map["SHIFT"]="not pressed";}
      if((keyboard_value%2048)/1024==1){
            key_map["CTRL"]="pressed";
        }
      else{key_map["CTRL"]="not pressed";}
        if((keyboard_value%1024)/512==1) {
            key_map["Q"] = "pressed";
        }
        else{key_map["Q"]="not pressed";}
        if((keyboard_value%512)/256==1){
            key_map["E"]="pressed";
        }
        else{key_map["E"]="not pressed";}
        if((keyboard_value%256)/128==1) {
            key_map["R"] = "pressed";
        }
        else{key_map["R"]="not pressed";}
        if((keyboard_value%128)/64==1){
            key_map["F"]="pressed";
        }
        else{key_map["F"]="not pressed";}
        if((keyboard_value%64)/32==1) {
            key_map["G"] = "pressed";
        }
        else{key_map["G"]="not pressed";}
        if((keyboard_value%32)/16==1){
            key_map["Z"]="pressed";
        }
        else{key_map["Z"]="not pressed";}
        if((keyboard_value%16)/8==1) {
            key_map["X"] = "pressed";
        }
        else{key_map["X"]="not pressed";}
        if ((keyboard_value % 8) / 4 == 1) {
            key_map["C"] = "pressed";
        }
        else{key_map["C"]="not pressed";}
        if ((keyboard_value % 4) / 2 == 1) {
            key_map["V"] = "pressed";
        }
        else{key_map["V"]="not pressed";}
        if ((keyboard_value % 2) / 1 == 1) {
            key_map["B"] = "pressed";
        }
        else{key_map["B"]="not pressed";}
    }
    void show()override {
        cout << "mouse_x:" << mouse_x << endl;
        cout << "mouse_y:" << mouse_y << endl;
        cout << "mouse_z:" << mouse_z << endl;
        cout << "left_button_down:" << left_button_down << endl;
        cout << "right_button_down:" << right_button_down << endl;
        keyboard();
        for (const auto &i: key_map) {
            cout << i.first << ":" << i.second << endl;
        }
    }
};
struct ext_client_map_command_t:public base{
    uint16_t target_robot_ID;
    float target_position_x;
    float target_position_y;
    void refresh(const vector<string>& package) override{
        target_robot_ID=stoi(package[7]+package[8],nullptr,16);
        target_position_x=stoi(package[9]+package[10]+package[11]+package[12],nullptr,16);
        target_position_y=stoi(package[13]+package[14]+package[15]+package[16],nullptr,16);
    }
    map<uint8_t,string> target_robot_ID_map{
            {1,"red_hero"},
            {2,"red_engineer"},
            {3,"red_inf"},
            {4,"red_inf"},
            {5,"red_inf"},
            {6,"red_air"},
            {7,"red_guard"},
            {8,"red_dart"},
            {9,"red_rader"},
            {10,"red_outpost"},
            {11,"red_base"},
            {101,"blue_hero"},
            {102,"blue_engineer"},
            {103,"blue_inf"},
            {104,"blue_inf"},
            {105,"blue_inf"},
            {106,"blue_air"},
            {107,"blue_guard"},
            {108,"blue_dart"},
            {109,"blue_rader"},
            {110,"blue_outpost"},
            {111,"blue_base"},
    };
    void show()override{
        cout<<"target_robot_ID:"<<target_robot_ID_map[target_robot_ID]<<endl;
        cout<<"target_position_x:"<<target_position_x<<"m"<<endl;
        cout<<"target_position_y:"<<target_position_y<<"m"<<endl;
    }
};
namespace crc{
    //these are standard crc_polynomial,I don't know what polynomial is used in the data provided.
    string crc_8="111010101";
    string crc_16="11000000000000101";
    string htb(const string& s){
        string res;
        for(auto i:s){
            if(i=='0'){res+="0000";}
            else if(i=='1'){res+="0001";}
            else if(i=='2'){res+="0010";}
            else if(i=='3'){res+="0011";}
            else if(i=='4'){res+="0100";}
            else if(i=='5'){res+="0101";}
            else if(i=='6'){res+="0110";}
            else if(i=='7'){res+="0111";}
            else if(i=='8'){res+="1000";}
            else if(i=='9'){res+="1001";}
            else if(i=='A'){res+="1010";}
            else if(i=='B'){res+="1011";}
            else if(i=='C'){res+="1100";}
            else if(i=='D'){res+="1101";}
            else if(i=='E'){res+="1110";}
            else if(i=='F'){res+="1111";}
        }
        return res;
    }
    string get_package_b(const vector<string>& package){
        string res;
        auto len=package.size();
        auto temp=package|views::take(len-2)|ranges::to<vector<string>>();
        for(const auto& i:package){
            res+=htb(i);
        }
        return res;
    }

    void single_8(string& s,int index){
        for(auto i:views::iota(0,9)){
            auto temp1=stoi(s.substr(index+i,1),nullptr,2);
            auto temp2=stoi(crc_8.substr(i,1),nullptr,2);
            auto temp3=temp1 xor temp2;
            if(temp3==0){s[index+i]=0;}
            else{s[index+i]=1;}
        }
    }
    void single_16(string& s,int index){
        for(auto i:views::iota(0,17)){
            auto temp1=stoi(s.substr(index+i,1),nullptr,2);
            auto temp2=stoi(crc_16.substr(i,1),nullptr,2);
            auto temp3=temp1 xor temp2;
            if(temp3==0){s[index+i]=0;}
            else{s[index+i]=1;}
        }
    }
    string bin_to_hex(const string& s){
        string res;
        int len=s.size();
        for(auto i:views::iota(0,len/4)){
            auto temp=s.substr(4*i,4);
            if(temp=="0000"){res+="0";}
            else if(temp=="0001"){res+="1";}
            else if(temp=="0010"){res+="2";}
            else if(temp=="0011"){res+="3";}
            else if(temp=="0100"){res+="4";}
            else if(temp=="0101"){res+="5";}
            else if(temp=="0110"){res+="6";}
            else if(temp=="0111"){res+="7";}
            else if(temp=="1000"){res+="8";}
            else if(temp=="1001"){res+="9";}
            else if(temp=="1010"){res+="A";}
            else if(temp=="1011"){res+="B";}
            else if(temp=="1100"){res+="C";}
            else if(temp=="1101"){res+="D";}
            else if(temp=="1110"){res+="E";}
            else if(temp=="1111"){res+="F";}
        }
        return res;
    }
    string get_crc_code_8(const vector<string>& package){
        auto bin_pack= get_package_b(package);
        auto origin=bin_pack+"00000000";
        int len=origin.size();
        for(auto i:views::iota(0,len-8)){
            if(origin[i]=='1'){
                single_8(origin,i);
            }
        }
        return bin_to_hex(origin.substr(len-8,8));
    }
    string get_crc_code_16(const vector<string>& package){
        auto bin_pack= get_package_b(package);
        auto origin=bin_pack+"0000000000000000";
        int len=origin.size();
        for(auto i:views::iota(0,len-16)){
            if(origin[i]=='1'){
                single_16(origin,i);
            }
        }
        return bin_to_hex(origin.substr(len-16,16));
    }
};
int main(){
    //input all commands
    string s;getline(cin,s);
    auto v=s|views::split(' ')|ranges::to<vector<string>>();
    // find first package
    v=v|views::drop_while([](const string& i){return(i!="A5");})|ranges::to<vector<string>>();
    //init all struct
    auto init=[](){vector<unique_ptr<base>> vec;
        vec.emplace_back(make_unique<ext_game_status_t>());
        vec.emplace_back(make_unique<ext_game_result_t>());
        vec.emplace_back(make_unique<ext_game_robot_HP_t>());
        vec.emplace_back(make_unique<ext_ICRA_buff_debuff_zone_and_lurk_status_t>());
        vec.emplace_back(make_unique<ext_event_data_t>());
        vec.emplace_back(make_unique<ext_supply_projectile_action_t>());
        vec.emplace_back(make_unique<exf_referee_warning_t>());
        vec.emplace_back(make_unique<ext_dart_remaining_time_t>());
        vec.emplace_back(make_unique<ext_game_robot_status_t>());
        vec.emplace_back(make_unique<ext_power_heat_data_t>());
        vec.emplace_back(make_unique<ext_game_robot_pos_t>());
        vec.emplace_back(make_unique<ext_buff_t>());
        vec.emplace_back(make_unique<aerial_robot_energy_t>());
        vec.emplace_back(make_unique<ext_robot_hurt_t>());
        vec.emplace_back(make_unique<ext_shoot_data_t>());
        vec.emplace_back(make_unique<ext_bullet_remaining_t>());
        vec.emplace_back(make_unique<ext_rfid_status_t>());
        vec.emplace_back(make_unique<ext_dart_client_cmd_t>());
        vec.emplace_back(make_unique<robot_interactive_data_t>());
        vec.emplace_back(make_unique<robot_interactive_data_with_self_made_controller>());
        vec.emplace_back(make_unique<ext_robot_command_t_map_client>());
        vec.emplace_back(make_unique<ext_robot_command_t_controller>());
        vec.emplace_back(make_unique<ext_client_map_command_t>());
        return(vec);};
    auto data_v=init();
    //from package get com
    auto get_com=[](const vector<string>& package){return(pair{package[5],package[6]});};
    //from package get seq
    auto get_seq=[](const vector<string>& package){return(package[3]);};
    //get com and use com to get index of refreshing struct in struct object vector
    auto get_index=[&](const vector<string>& package){
        const auto com=get_com(package);
        const auto com1=stoi(com.first,nullptr,16);
        const auto com2=stoi(com.second,nullptr,16);
        auto index=com2-1;
        if(com1==1){index+=5;}
        else if(com1==2){index+=10;}
        else if(com1==3){index+=20;}
        //if command id is wrong,return -1
        if(com1>3 or com2>10 or((com1==0 or com1==1 or com1==3) and com2>5)){index=-1;}
        return(index);
        };
    // loop to decode all packages and refresh structs
    while(!v.empty()){
        const auto l=v[1];
        const auto length=stoi(l,nullptr,16);
        //get a package
        const auto package_temp=ranges::take_view{v,length+9}|ranges::to<vector<string>>();
        //delete this package in all packages
        v=ranges::drop_view{v,length+9}|ranges::to<vector<string>>();
        //decode this package
        auto crc_from_package=package_temp[package_temp.size()-2]+package_temp[package_temp.size()-1];
        auto crc_from_compute=crc::get_crc_code_16(package_temp);
        if(get_index(package_temp)!=-1 and crc_from_package==crc_from_compute){
        cout<<"package seq:"<<get_seq(package_temp)<<endl;
        data_v[get_index(package_temp)]->refresh(package_temp);}
    }
    //finally show all structs in the end
    for(auto& i:data_v){i->show();}
    return 0;
}
