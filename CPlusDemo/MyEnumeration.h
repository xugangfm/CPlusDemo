//
//  MyEnumeration.h
//  CPlusDemo
//
//  Created by xugang on 15/7/23.
//  Copyright (c) 2015年 RongCloud. All rights reserved.
//

#ifndef __CPlusDemo__MyEnumeration__
#define __CPlusDemo__MyEnumeration__

#include <stdio.h>

enum Collor { yellow = 100,
    red = 2 };

#define MSG_TYPE_DATA(a, b, c) a = b,
enum class MsgType {
    MSG_TYPE_DATA(UNKNOWN, 0, "")
        MSG_TYPE_DATA(SYSTEM, 1, "system")
            MSG_TYPE_DATA(PRIVATE, 2, "private")
                MSG_TYPE_DATA(GROUP, 3, "group")
                    MSG_TYPE_DATA(DISCUSSION, 4, "discussion")
                        MSG_TYPE_DATA(POST_SYSTEM, 101, "post_system")
                            MSG_TYPE_DATA(POST_PRIVATE, 102, "post_private")
                                MSG_TYPE_DATA(POST_GROUP, 103, "post_group")
                                    MSG_TYPE_DATA(POST_DISCUSSION, 104, "post_discussion")

};
#undef MSG_TYPE_DATA
#endif /* defined(__CPlusDemo__MyEnumeration__) */
