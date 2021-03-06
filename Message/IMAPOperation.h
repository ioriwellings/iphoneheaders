/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/Message.framework/Message
 */

#import <Foundation/NSObject.h>
#import "Message-Structs.h"

@class NSString, NSArray;

@interface IMAPOperation : NSObject {
	unsigned _type : 8;
	unsigned _temporaryUids : 1;
	NSString* _mailboxName;
	union {
		struct {
			NSArray* trueFlags;
			NSArray* falseFlags;
			CFArrayRef uids;
		} store;
		struct {
			unsigned uid;
			NSArray* flags;
			int internalDate;
			unsigned size;
		} append;
		struct {
			CFArrayRef srcUids;
			CFArrayRef dstUids;
			NSString* destinationMailbox;
		} copy;
	} _opSpecific;
}
+(id)deserializeFromData:(id)data cursor:(unsigned*)cursor;
-(unsigned char)_magic;
-(void)_deserializeOpSpecificValuesFromData:(id)data cursor:(unsigned*)cursor;
-(void)serializeIntoData:(id)data;
-(id)initWithMailboxToCreate:(id)create;
-(id)initWithMailboxToDelete:(id)aDelete;
-(id)initWithFlagsToSet:(id)set flagsToClear:(id)clear forUids:(id)uids inMailbox:(id)mailbox;
-(id)initWithUidsToCopy:(id)copy fromMailbox:(id)mailbox toMailbox:(id)mailbox3 firstNewUid:(unsigned)uid;
-(id)initWithAppendedUid:(unsigned)appendedUid approximateSize:(unsigned)size flags:(id)flags internalDate:(id)date mailbox:(id)mailbox;
// inherited: -(void)dealloc;
-(BOOL)isSourceOfTemporaryUid:(unsigned)temporaryUid;
-(BOOL)actsOnTemporaryUid:(unsigned)uid;
-(void)expungeTemporaryUid:(unsigned)uid;
-(unsigned)firstTemporaryUid;
-(unsigned)lastTemporaryUid;
-(int)operationType;
-(id)mailboxName;
-(unsigned)approximateSize;
-(BOOL)usesRealUids;
-(void)setUsesRealUids:(BOOL)uids;
-(id)flagsToSet;
-(id)flagsToClear;
-(id)uids;
-(id)flags;
-(id)internalDate;
-(unsigned)uid;
-(id)sourceUids;
-(id)destinationUids;
-(id)destinationMailbox;
-(unsigned)sourceUidForTemporaryUid:(unsigned)temporaryUid;
-(BOOL)getMessageId:(id*)anId andInternalDate:(id*)date forDestinationUid:(unsigned)destinationUid;
-(void)setMessageId:(id)anId andInternalDate:(id)date forMessageWithSourceUid:(unsigned)sourceUid;
// inherited: -(id)description;
@end

