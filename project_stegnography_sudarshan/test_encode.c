/***************************************************************************************************************************************

NAME          :    Sudarshan C S
DATE          :    15-01-2022
DESCRIPTION   :    Project to encode secret data into original image and decode that secret data (STEGNOGRAPHY)
INPUT         :
OUTPUT        :

./a.out -e beautiful.bmp secret.txt 

SELECTED ENCODING
Read and validation is successful
Open files is successful
STARTED ENCODING......
Check capacity is successful
Copied the header successfully
Encoded magic string successfully
Encoded secret file extension size successfully
Encoded extension successfully
Encoded secret file size
Encoded secret file data successfully
Copied remaining data successfully
COMPLETED ENCODING

./a.out -d stego.bmp

SELECTED DECODING
Read and validation is successful
Opening File Successfully
STARTED DECODING........
Decoded Magic String Successfully
Decoded File Extension Successfully
Decoded Secret File Extension Successfully
Decoded Secret File Size Successfully
Decoded Secret File Data Successfully
COMPLETED DECODING


****************************************************************************************************************************************/


#include <stdio.h>
#include<string.h>
#include"common.h"
#include "encode.h"
#include "types.h"
#include"decode.h"

int main(int argc, char *argv[])
{
    if(argc >= 4)
    {
        if (check_operation_type(argv) == e_encode)
        {
            printf("Selected encoding.......\n");
            EncodeInfo encInfo;
            if(read_and_validate_encode_args(argv, &encInfo) == e_success)
            {
                printf("Read and validate encode argument is a success\n");
                printf("<--------------------started Encoding-------------------->\n");
                if(do_encoding(&encInfo) == e_success)
                {
                    printf("Encoded successfully\n");

                }
                else
                {
                    printf("Failed to encode\n");
                    return -1;
                }

            }
            else
            {
                printf("Read and validate encode arguments is a faliure\n");
                return -1;
            }

        }
        else if(check_operation_type(argv) == e_decode)
        {
            printf("Sectecting decoding........\n");
            DecodeInfo decInfo;
            if(read_and_validate_decode_args(argv, &decInfo) == d_success)
            {
                printf("Read and validate decode arguments is a success\n");
                printf("<----------------started decoding----------------->\n");
                if(do_decoding(&decInfo) == e_success)
                {
                    printf("Decoded successfully\n");
                }
                else
                {
                    printf("Failed to decode\n");
                }
            }
            else
            {
                printf("Read and validate decode arguments is a failure\n");
                return -1;
            }
        }
        else
        {
            printf("Invalid otion\nPleases pass for \nEncoding:./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding:./a.out -d stego.bmp decode.txt\n");
        }
    }
    else
    {
        printf("Error: please pass minimum 4 argument\n");
    }
    return 0;

}

