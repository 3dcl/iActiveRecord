//
//  JoinSpec.mm
//  iActiveRecord
//
//  Created by Alex Denisov on 01.08.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import "SpecHelper.h"

#import "ARDatabaseManager.h"
#import "User.h"
#import "Group.h"
#import "ARLazyFetcher.h"

using namespace Cedar::Matchers;

SPEC_BEGIN(JoinSpecs)

beforeEach(^{
    prepareDatabaseManager();
    [[ARDatabaseManager sharedManager] clearDatabase];
});
afterEach(^{
    [[ARDatabaseManager sharedManager] clearDatabase];
});

describe(@"Join", ^{
    beforeEach(^{
        for(int i=0;i<10;i++){
            Group *group = [Group record];
            group.title = [NSString stringWithFormat:@"group%d", i];
            [group save];
            User *user = [User record];
            user.name = [NSString stringWithFormat:@"user%d", i];
            user.groupId = group.id;
            [user save];
        }
    });
    it(@"should return array of dictionaries", ^{
        ARLazyFetcher *fetcher = [[User query] join:[Group class]
                                                  useJoin:ARJoinInner
                                                  onField:@"groupId"
                                                 andField:@"id"];
        NSArray *records = [fetcher fetchJoinedRecords];
        id first = [records objectAtIndex:0];
        BOOL result = [first isKindOfClass:[NSDictionary class]];
        result should be_truthy;
    });
    it(@"returned dictionary should contain fields of two records", ^{
        ARLazyFetcher *fetcher = [[User query] join:[Group class]
                                                  useJoin:ARJoinInner
                                                  onField:@"groupId"
                                                 andField:@"id"];
        NSArray *records = [fetcher fetchJoinedRecords];
        NSDictionary *first = [records objectAtIndex:0];
        NSArray *keys = [first allKeys];
        BOOL result = [keys containsObject:@"User"] && [keys containsObject:@"Group"];
        result should be_truthy;
    });
});

SPEC_END
