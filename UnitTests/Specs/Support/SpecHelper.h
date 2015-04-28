//
//  SpecHelper.h
//  iActiveRecord
//
//  Created by Alex Denisov on 19.05.13.
//  Copyright (c) 2013 okolodev.org. All rights reserved.
//

#import <Cedar-iOS.h>
#import <CedarAsync/CedarAsync.h>
#import "Tsuga.h"

#import "ARConfiguration.h"
#import "ActiveRecord.h"

static void prepareDatabaseManager() {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        [ActiveRecord applyConfiguration:^(ARConfiguration *config) {
            config.databasePath = ARCachesDatabasePath(nil);
        }];
    });
}
