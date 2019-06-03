#include <bitcoin/system.hpp>


#define EC_PUBLICKEY    "0482d8f11180378eda60aa36d1d3d160d514ec932ffbb5fe855f7d04be65a7b99a5971d6c5a1acac1edefe009d6a887646d2c21e99f267af4a8518ba71483624f0"
#define EC_SIGNATURE    "3fcd6ddbe2bdacf34cab305bb86c79b7d907f04368d13a8ef4f1097b14080c023603e5263c89d74c45a20872fd3c8f03c18d3ac0c5357b3ab365d47975b017d3"

/************************************************************************/
/*
#define HASHMSG     "000000000000000000000000000000000000004b5a656e204e6574776f726b73"
#define EC_R        "3fcd6ddbe2bdacf34cab305bb86c79b7d907f04368d13a8ef4f1097b14080c02"
#define EC_S        "3603e5263c89d74c45a20872fd3c8f03c18d3ac0c5357b3ab365d47975b017d3"
#define EC_X        "82d8f11180378eda60aa36d1d3d160d514ec932ffbb5fe855f7d04be65a7b99a"
#define EC_Y        "5971d6c5a1acac1edefe009d6a887646d2c21e99f267af4a8518ba71483624f0"
*/
/************************************************************************/

#if 1
#if 0
 #define HASHMSG     "ce0677bb30baa8cf067c88db9811f4333d131bf8bcf12fe7065d211dce971008"
 #define EC_R        "da8cda7f0fe4d7f4d9fb3509d2609e1e74843bab9145da440f6b07475cf8418f"
 #define EC_S        "e01e5fe639ede14fd58f97cf5de0718fbdb8fb0666a043ac087fadff88870cd6"
 #define EC_X        "2705a077a1d516d406f36bd50421a2ebd5035d30085e010e0d8130504bb031df"
 #define EC_Y        "db1ac28167ad41aec921cd87a82594cbd396b27e054c318458f12354f86c6919"
#else
#define HASHMSG     "000000000000000000000000000000000000004b5a656e204e6574776f726b73"
#define EC_R        "d2057447a843af3b71382dc8eec64b2908a86732d073a3cd0cdad0f368f3a08a"
#define EC_S        "6ebe1bbb6ff7ad9bfa7a35f075332ddb90bcd0e05994e0eeddb0a909631fff67"
#define EC_X        "2705a077a1d516d406f36bd50421a2ebd5035d30085e010e0d8130504bb031df"
#define EC_Y        "db1ac28167ad41aec921cd87a82594cbd396b27e054c318458f12354f86c6919"
#endif
#else
#define HASHMSG "ce0677bb30baa8cf067c88db9811f4333d131bf8bcf12fe7065d211dce971008"
#define EC_R    "90f27b8b488db00b00606796d2987f6a5f59ae62ea05effe84fef5b8b0e54998"
#define EC_S    "4a691139ad57a3f0b906637673aa2f63d1f55cb1a69199d4009eea23ceaddc93"
#define EC_X    "e32df42865e97135acfb65f3bae71bdc86f4d49150ad6a440b6f15878109880a"
#define EC_Y    "0a2b2667f7e725ceea70c673093bf67663e0312623c8e091b13cf2c0f11ef652"
//    testpubkeyc = hexutil.MustDecode("0x02e32df42865e97135acfb65f3bae71bdc86f4d49150ad6a440b6f15878109880a")
#endif




int verifysig(std::string R, std::string S);

int main(int argc, char *argv[]) {    
/*
    bc::system::data_chunk privatekey;
    bc::system::decode_base58(privatekey, "5JaTXbAUmfPYZFRwrYaALK48fN6sFJp4rHqq2QSXs8ucfpE4yQU");    

    // Private secret key.    
    bc::system::ec_secret secret;
    bc::system::decode_hash(secret, "038109007313a5807b2eccc082c8c3fbb988a973cacf1a7df9ce725c31b14776");  
    
    for(int i=0;i<32;i++)
        secret[i] = privatekey[i+1]; // type + value + checksum
    std::cout << "Private key: " << bc::system::encode_base16(secret) << std::endl;

    // Get public key.    
    bc::system::ec_uncompressed public_key;
    bc::system::secret_to_public(public_key, secret);    

    std::cout << "Public key: " << bc::system::encode_base16(public_key) << std::endl;

    // Create Bitcoin address.    
    // Normally you can use:    
    //   bc::payment_address payaddr;    
    //   bc::set_public_key(payaddr, public_key);    
    //   const std::string address = payaddr.encoded();

    // Compute hash of public key for P2PKH address.    
    const bc::system::short_hash hash = bc::system::bitcoin_short_hash(public_key);    
    bc::system::data_chunk unencoded_address; // Reserve 25 bytes   
    // [ version:1 ]    
    // [ hash:20 ]    
    //   [ checksum:4 ]    
    unencoded_address.reserve(25);    
    // Version byte, 0 is normal BTC address (P2PKH).   
    unencoded_address.push_back(0);    
    // Hash data    
    bc::system::extend_data(unencoded_address, hash);    
    // Checksum is computed by hashing data, and adding 4 bytes from hash. 
    bc::system::append_checksum(unencoded_address);    
    // Finally we must encode the result in Bitcoin's base58 encoding assert(unencoded_address.size() == 25);    
    const std::string address = bc::system::encode_base58(unencoded_address);    
    std::cout << "Address: " << address << std::endl;    
*/

    std::string r = EC_R;
    std::string s = EC_S;
    if( argc > 1 )
    {
        r = argv[1];
        s = argv[2];
    }

    if( verifysig(r, s) )
    {
        std::cout << "verify succeed" << std::endl;    
    }
    else
        std::cout << "verify failed" << std::endl;    


    return 0; 
}

/*
int verify()
{
    std::cout << "*************** verify signature ***************************" << std::endl;
    bc::system::ec_uncompressed point;
    bc::system::ec_signature signature;

    bc::system::hash_digest r,s,x,y, hash;
    bc::system::hash_digest rr,sr,xr,yr, hashr;

    bc::system::decode_hash(r, EC_R);
    bc::system::decode_hash(s, EC_S);
    bc::system::decode_hash(x, EC_X);
    bc::system::decode_hash(y, EC_Y);
    bc::system::decode_hash(hash, HASHMSG);

    std::reverse_copy(hash.begin(), hash.end(), hashr.begin());
    std::reverse_copy(r.begin(), r.end(), rr.begin());
    std::reverse_copy(s.begin(), s.end(), sr.begin());
    std::reverse_copy(x.begin(), x.end(), xr.begin());
    std::reverse_copy(y.begin(), y.end(), yr.begin());

    point[0] = 4;
    std::copy(xr.begin(), xr.end(), point.begin()+1);
    std::copy(yr.begin(), yr.end(), point.begin()+33);

    std::copy(r.begin(), r.end(), signature.begin());
    std::copy(s.begin(), s.end(), signature.begin()+32);

    std::cout << "Public key: " << bc::system::encode_base16(point) << std::endl;
    std::cout << "hashed message: " << bc::system::encode_base16(hashr) << std::endl;
    std::cout << "signature: " << bc::system::encode_base16(signature) << std::endl;

    bool flag = bc::system::verify_signature(point, hashr, signature);

    return flag;
}
*/

int verifysig(std::string R, std::string S)
{
    std::cout << "*************** verify signature ***************************" << std::endl;
    bc::system::ec_uncompressed point;
    bc::system::ec_signature signature;

    bc::system::hash_digest r,s,x,y, hash;
    bc::system::hash_digest rr,sr,xr,yr, hashr;

    bc::system::decode_hash(r, R);
    bc::system::decode_hash(s, S);
    bc::system::decode_hash(x, EC_X);
    bc::system::decode_hash(y, EC_Y);
    bc::system::decode_hash(hash, HASHMSG);

    std::reverse_copy(hash.begin(), hash.end(), hashr.begin());
    std::reverse_copy(r.begin(), r.end(), rr.begin());
    std::reverse_copy(s.begin(), s.end(), sr.begin());
    std::reverse_copy(x.begin(), x.end(), xr.begin());
    std::reverse_copy(y.begin(), y.end(), yr.begin());

    point[0] = 4;
    std::copy(xr.begin(), xr.end(), point.begin()+1);
    std::copy(yr.begin(), yr.end(), point.begin()+33);

    std::copy(r.begin(), r.end(), signature.begin());
    std::copy(s.begin(), s.end(), signature.begin()+32);

    std::cout << "Public key: " << bc::system::encode_base16(point) << std::endl;
    std::cout << "hashed message: " << bc::system::encode_base16(hashr) << std::endl;
    std::cout << "signature: " << bc::system::encode_base16(signature) << std::endl;

    bool flag = bc::system::verify_signature(point, hashr, signature);

    return flag;
}


