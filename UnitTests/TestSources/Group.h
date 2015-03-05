//
//  Group.h
//  iActiveRecord
//
//  Created by Alex Denisov on 10.01.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import "VinylRecord.h"

/*
    Group has many users
 */

@interface Group : VinylRecord
has_many_dec(User, users, ARDependencyDestroy)
has_many_through_dec(Project, ProjectGroupRelationship, groups, ARDependencyNullify)
column_dec(string,title)
@end
