//
//  ARDatabaseManager.m
//  iActiveRecord
//
//  Created by Alex Denisov on 10.01.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@class ActiveRecord;
@class ARConfiguration;


@interface ARDatabaseConnection : NSObject {}
@property (nonatomic, readonly)  sqlite3 *database ;
@property(nonatomic,retain) ARConfiguration *configuration;
+ (instancetype) connectionWithConfiguration: (ARConfiguration *) config;
- (id) initWithConfiguration: (ARConfiguration*) config;
@end


@interface ARDatabaseManager : NSObject {}

@property (nonatomic, strong) ARConfiguration *configuration;

- (void)createDatabase;
- (void)clearDatabase;

- (void)createTables;
- (void)createTable:(id)aRecord;
- (void)appendMigrations;

- (NSArray *)tables;
- (NSArray *)views;
- (NSArray *)columnsForTable:(NSString *)aTableName;

- (NSString *)tableName:(NSString *)modelName;

+ (instancetype)sharedManager;
- (void)applyConfiguration:(ARConfiguration *)configuration;

- (NSNumber *)getLastId:(NSString *)aRecordName;
- (NSArray *)allRecordsWithName:(NSString *)aName withSql:(NSString *)aSqlRequest;
- (NSArray *)joinedRecordsWithSql:(NSString *)aSqlRequest;
- (NSInteger)countOfRecordsWithName:(NSString *)aName;
- (NSInteger)functionResult:(NSString *)anSql;

- (NSInteger)saveRecord:(ActiveRecord *)aRecord;
- (NSInteger)updateRecord:(ActiveRecord *)aRecord;
- (void)dropRecord:(ActiveRecord *)aRecord;
- (BOOL)executeSqlQuery:(const char *)anSqlQuery;

- (void)createIndices;
- (void)createUniqueIndices;
- (NSArray *)records;

@end
