//
//  UnicodeSpecs.mm
//  iActiveRecord
//
//  Created by Alex Denisov on 01.08.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import "SpecHelper.h"

#import "ARDatabaseManager.h"
#import "User.h"

using namespace Cedar::Matchers;

SPEC_BEGIN(UnicodeSpecs)

beforeEach(^{
    prepareDatabaseManager();
    [[ARDatabaseManager sharedManager] clearDatabase];
});
afterEach(^{
    [[ARDatabaseManager sharedManager] clearDatabase];
});

describe(@"Unicode search", ^{
    it(@"should find records", ^{
        User *alex = [User record];
        alex.name = @"Алексей";
        [alex save];
        ARLazyFetcher *fetcher = [[User query] where:@"name LIKE '%%ксей%%'", nil];
        fetcher.count should_not equal(0);
    });
});

SPEC_END
