//
//  Project.h
//  iActiveRecord
//
//  Created by Alex Denisov on 22.03.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import "VinylRecord.h"
//#import "User.h"

/*
    Project has many users
 */

@interface Project : VinylRecord
has_many_dec(Issue, issues, ARDependencyDestroy)
has_many_through_dec(User, UserProjectRelationship, users, ARDependencyDestroy)
has_many_through_dec(CustomUser, CustomUserProjectRelationship, custom_users, ARDependencyDestroy)
has_many_through_dec(Group, ProjectGroupRelationsShip, groups, ARDependencyNullify)
column_dec(string,name)
@end
