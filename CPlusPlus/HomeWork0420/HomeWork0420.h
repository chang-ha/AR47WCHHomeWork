#pragma once
#include <GameEngineBase/GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginepair
{
public:
	KeyType first;
	ValueType second;
	GameEnginepair()
	{

	}
	GameEnginepair(const KeyType& _Key, const ValueType& _Value)
		:first(_Key), second(_Value)
	{

	}

};

class GameEngineMap
{
public:
	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginepair Pair;

		MapNode* OverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first > ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;
				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}

			return ParentNode;
		}

		MapNode* rOverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first < ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;
				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}
			return ParentNode;
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}
			return LeftChild->MinNode();
		}

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}
			return RightChild->MaxNode();
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				// ������ �ڽ��� �ִٸ� ������ �ڽ��� MinNode(���� ���� Key)
				return RightChild->MinNode();
			}
			if (nullptr != Parent)
			{
				// ������ �ڽ��� ���ٸ� �θ����
				// �θ���� �� �� ������ Key���� ū �θ��带 ã�� �� ���� ��ȸ
				return OverParentNode();
			}
			// ������ ��嵵 ���� ������ ū Key���� ���� ��尡 ������ �ش� map������ MaxNode��
			// MaxNode�� �������� nullptr(end)
			return nullptr;
		}

		MapNode* PrevNode()
		{
			if (nullptr != LeftChild)
			{
				return LeftChild->MaxNode();
			}
			if (nullptr != Parent)
			{
				return rOverParentNode();
			}
			return nullptr;
		}

		bool insert(MapNode* _NewNode)
		{
			// ���� ���� ����� Key���� Root����� Key������ ������ �����ڽ�����
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					// �����ڽ��� �̹� �ִٸ� insert ���
					return LeftChild->insert(_NewNode);
				}
				LeftChild = _NewNode;
				// ���� ���� Node�� �θ���� ���� �Լ��� ȣ������ ���
				_NewNode->Parent = this;
				return true;
			}
			// ���� ���� ����� Key���� Root����� Key������ ũ�� �������ڽ�����
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					// �������ڽ��� �̹� �ִٸ� insert ���
					return RightChild->insert(_NewNode);
				}
				RightChild = _NewNode;
				// ���� ���� Node�� �θ���� ���� �Լ��� ȣ������ ���
				_NewNode->Parent = this;
				return true;
			}
			// ���� ���� ����� Key���� ������ Key���� ���� ��尡 �̹� �ʿ� ������
			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					// Key���� ���� ����� Key������ ������ ��������
					return LeftChild->find(_Key);
				}
				// �����ڽ��� nullptr�̸� ��ã�� ���̴� nullptr
				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					// Key���� ���� ����� Key������ ũ�� ����������
					return RightChild->find(_Key);
				}
				// �������ڽ��� nullptr�̸� ��ã�� ���̴� nullptr
				return nullptr;
			}
			// ������ �Լ��� ȣ������ ����� iterator�� ����
			return this;
		}
	};

	class iterator
	{
		friend GameEngineMap;
	public:
		iterator()
		{

		}

		iterator(class MapNode* _Node)
			: Node(_Node)
		{

		}

		GameEnginepair* operator->()
		{
			return &Node->Pair;
		}

		bool operator==(const iterator& _Other) const
		{
			return Node == _Other.Node;
		}

		bool operator!=(const iterator& _Other) const
		{
			return Node != _Other.Node;
		}

		iterator& operator++()
		{
			// ++������ == �� ���� ��带 �����Ѿ���
			// �� ���� ����??? �� RightChild�� MinNode()
			// ���� RightChile == nullptr�̸�??? �θ������� �ö󰡾���
			Node = Node->NextNode();
			return *this;
		}

		iterator& operator--()
		{
			// --������ << �� ���� ��带 �����Ѿ���
			// �� ���� ����??? �� LeftChild�� MaxNode()
			// ���� LeftChild == nullptr�̸�??? �θ������� �ö󰡾���
			Node = Node->PrevNode();
			return *this;
		}
	private:
		// ���漱��
		class MapNode* Node = nullptr;
	};

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}
		return iterator(Root->MinNode());
	}

	iterator end()
	{
		// Node�� nullptr�� �༮�� end == �ƹ��� ����Ű�� �ʴ� �༮
		return iterator();
	}

	iterator rbegin()
	{
		if (nullptr == Root)
		{
			return end();
		}
		return iterator(Root->MaxNode());
	}

	iterator rend()
	{
		return iterator();
	}

	iterator find(const KeyType _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}
		MapNode* FindNode = Root->find(_Key);
		return iterator(FindNode);
	}

	// �ȵ��� false����
	bool insert(const GameEnginepair& _Pair)
	{
		if (nullptr == Root)
		{
			// �Ѹ���尡 �������� ������
			// ������ �Ѹ���尡 ��
			Root = new MapNode();
			Root->Pair = _Pair;
			return true;
		}
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Pair;
		if (false == Root->insert(NewNode))
		{
			delete NewNode;
			NewNode = nullptr;
			return false;
		}
		return true;
	}


	MapNode* Root = nullptr;

protected:

private:
};